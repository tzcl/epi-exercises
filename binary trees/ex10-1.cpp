// Write a program that takes as input the root of a binary tree and checks
// whether the tree is height-balanced.
//
// A binary tree is said to be height-balanced if for each node in the tree, the
// difference in the height of its left and right subtrees is at most one.

#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};

// Ideas: want to compare heights of left and right subtrees
// How do I want to traverse the tree? I think pre-order
// Should I also write a recursive method?

// Writing an iterative version seems really hard
template <typename T>
bool is_height_balanced(unique_ptr<BinaryTreeNode<T>> root) {
  stack<BinaryTreeNode<T> *> s({root.get()});

  while (!s.empty()) {
    auto node = s.top();
    s.pop();

    if (node) {
      // is this possible? seems really hard
      s.push(node->left);
      s.push(node->right);
    }
  }
}

// The problem with this approach is that I'm not checking to see if each node
// in the tree is balanced.
//
// The optimal approach is to realise that heights must be non-negative.
// Therefore, we can encode if a subtree is balanced by setting the height to
// -1.

template <typename T> int height(unique_ptr<BinaryTreeNode<T>> root) {
  if (!root)
    return 0;

  int left_subtree = height(root->left);
  if (left_subtree == -1)
    return -1;

  int right_subtree = height(root->right);
  if (right_subtree == -1)
    return -1;

  if (abs(left_subtree - right_subtree) > 1)
    return -1;
  return max(left_subtree, right_subtree) + 1;
}

template <typename T> bool is_balanced(unique_ptr<BinaryTreeNode<T>> root) {
  return height(root) != -1; // note, this is much faster than >= 0!
}
