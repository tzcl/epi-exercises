// Write a program that takes as input a binary tree and checks if the tree
// satisfies the BST property.

#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BSTNode {
  T data;
  unique_ptr<BSTNode<T>> left, right;
};

// The BST property is global -- all keys in the left subtree tree must be <=
// root key and all keys in the right subtree must be >=
//
// Perform in-order traversal and check everything is ok (don't know how to
// implement)
//
// Had absolutely no idea, brute force approach was to find the maximum in the
// left subtree and the minimum in the right subtree.
//
// The problem with that approach is that it repeats work -- traverse subtrees
// over and over again
//
// A better approach is in-order traversal like I identified which has O(n) time
// complexity and O(h) additional space complexity. The key idea is that you can
// tighten a range as you traverse the tree and check that this holds for all
// nodes.

// Implementing in-order traversal (BFS!)
struct QueueEntry {
  const unique_ptr<BSTNode<int>> &node;
  int lower_bound, upper_bound;
};

bool is_BST(const unique_ptr<BSTNode<int>> &root) {
  queue<QueueEntry> queue;
  queue.emplace(
      QueueEntry{root, numeric_limits<int>::min(), numeric_limits<int>::max()});

  while (!queue.empty()) {
    const auto &entry = queue.front();
    queue.pop();
    if (entry.node.get()) {
      if (entry.node->data < entry.lower_bound ||
          entry.node->data > entry.upper_bound)
        return false;

      queue.emplace(
          QueueEntry{entry.node->left, entry.lower_bound, entry.node->data});
      queue.emplace(
          QueueEntry{entry.node->right, entry.node->data, entry.upper_bound});
    }
  }

  return true;
}

// failed attempt
struct Visit {
  bool ordered;
  int data;
};

Visit visit_node(unique_ptr<BSTNode<int>> &root) {
  if (!root)
    return {true, -1};

  auto left = visit_node(root->left);
  if (!left.ordered || left.data > root->data)
    return {false, root->data};

  auto right = visit_node(root->right);
  if (!right.ordered || root->data > right.data)
    return {false, root->data};
  return {true, root->data};
}

bool isBST(unique_ptr<BSTNode<int>> &root) { return visit_node(root).ordered; }
