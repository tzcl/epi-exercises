// The Dutch National Flag Problem
//
// Write a program that takes an array A and an index i into A, and rearranges
// the elements such that all elements less than A[i] (the "pivot") appear
// first, followed by the elements equal to the pivot, followed by elements
// greater than the pivot.

#include <bits/stdc++.h>

// Helper function to make code nicer
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// Not sure how to do this :-(
// I tried too hard to come up with a perfect solution straight away, should've
// come up with a brute force approach and optimised.
void arrange_array(std::array<int, 7> &A, int pivot) {
  int lower = 0;
  int higher = A.size() - 1;
  int tmp = 0;

  while (lower < higher) {
    if (A[lower] < A[pivot]) {
      lower++;
    } else {
      tmp = A[lower];
      A[lower] = A[higher];
      A[higher] = tmp;
      higher--;
    }
  }
}

// Start by doing two passes to group all elements smaller than the pivot at the
// start of the array, and all elements larger than the pivot at the end of the
// array. Then, notice that you can save a few operations by avoiding repeated
// iterations. There's a way to do this all in one iteration.
//
// Maintain four subarrays: bottom, middle, unclassified and top. Iterate
// through and assign all unclassified to bottom, middle or top.
void dutch_flag_partition(std::array<int, 7> &A, int pivot_index) {
  int lower = 0, equal = 0, greater = A.size() - 1;
  int pivot = A[pivot_index]; // constant!

  // for (int i = 0; i < A.size(); i++) USE WHILE LOOP
  while (equal <= greater) { // there are still unclassified elements
    // A[equal] is the next unclassified element
    if (A[equal] < pivot) {
      swap(A[lower++], A[equal++]);
    } else if (A[equal] == pivot) {
      equal++;
    } else {
      swap(A[equal], A[greater--]);
    }
  }
}

int main() {
  std::array<int, 7> A = {-3, 0, 1, 5, 3, -2, 1};
  std::array<int, 7> B = {0, 1, 2, 0, 2, 1, 1};
  int pivot = 2;

  for (int a : A) {
    std::cout << a << " ";
  }
  std::cout << std::endl;

  dutch_flag_partition(A, pivot);
  // arrange_array(A, pivot);

  for (int a : A) {
    std::cout << a << " ";
  }
  std::cout << std::endl;

  return 0;
}
