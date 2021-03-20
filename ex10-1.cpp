// Test if a binary tree is height-balanced. That is, for each node in the tree,
// the difference in the height of its left and right subtrees is at most one.

#include <bits/stdc++.h>

template <typename T> struct BinaryTreeNode {
  T data;
  std::unique_ptr<BinaryTreeNode<T>> left, right;
};

int height(std::unique_ptr<BinaryTreeNode<int>> root) {
  if (root) {
    int left_height = height(root->left);
    int right_height = height(root->right);

    return std::max(left_height, right_height) + 1;
  }

  return 0;
}

// Lots of duplicated work in recalculating the heights of subtrees.
// Instead of returning a bool, also return the height of the tree.
bool is_height_balanced(std::unique_ptr<BinaryTreeNode<int>> root) {
  if (root) {
    if (std::abs(height(root->left) - height(root->right)) > 1) {
      return false;
    }

    return is_height_balanced(root->left) && is_height_balanced(root->right);
  }

  return true;
}
