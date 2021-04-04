// Write a method that takes a sorted array and a key and returns the index of
// the first occurrence of that key in the array.

#include <bits/stdc++.h>
using namespace std;

// Brute force: binary search then check left O(n) worst-case
// Better solution: find directly??
//
// The key idea behind binary search is maintaining a set of candidates and
// eliminating them step-by-step.
// Might be slightly more efficient to have a result to keep track of the equals
// case and allow the candidate set to get smaller.

int find_first_better(vector<int> A, int key) {
  int low = 0, high = A.size() - 1;

  while (low < high) { // breaks when low >= high
    int mid = low + (high - low) / 2;
    if (key <= A[mid]) {
      high = mid;
    } else { // key > A[mid]
      low = mid + 1;
    }
  }

  return low;
}

int find_first(vector<int> A, int key) {
  int low = 0, high = A.size() - 1;
  int mid = low + (high - low) / 2;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (A[mid] == A[key]) {
      break;
    } else if (A[mid] < A[key]) {
      low = mid + 1;
    } else { // A[mid] > A[key]
      high = mid - 1;
    }
  }

  while (A[mid] == A[key])
    --mid;

  return mid;
}

int main() {
  vector<int> test = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};

  cout << find_first_better(test, 108) << " vs " << 3 << endl;
  cout << find_first_better(test, 285) << " vs " << 6 << endl;
}
