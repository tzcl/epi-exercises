// Given a binary tree, return an array consisting of the keys at the same
// level. Keys should appear in the order of the corresponding nodes' depths,
// breaking ties from left to right.
//
// Hint: First think about solving this problem with a pair of queues.

#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};

// Traverse the tree in depth order, use a queue to traverse the tree!
vector<vector<int>> same_level_keys(unique_ptr<BinaryTreeNode<int>> &root) {
  vector<vector<int>> result;
  queue<BinaryTreeNode<int> *> curr_depth({root.get()});

  while (!curr_depth.empty()) {
    vector<int> level;
    queue<BinaryTreeNode<int> *> next_depth;

    while (!curr_depth.empty()) {
      auto node = curr_depth.front();
      curr_depth.pop();

      level.push_back(node->data);

      if (node->left)
        next_depth.push(node->left.get());
      if (node->right)
        next_depth.push(node->right.get());
    }

    if (!level.empty()) {
      result.push_back(level);
    }

    curr_depth = next_depth;
  }

  return result;
}
