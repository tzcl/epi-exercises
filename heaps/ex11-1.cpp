// Write a program that takes as input a set of sorted sequences and computes
// the union of these sequences as a sorted sequence. For example, if the input
// is (3,5,7), (0,6), and (0,6,28), then the output is (0,0,3,5,6,6,7,28).

#include <bits/stdc++.h>
using namespace std;

// Idea: stream these inputs into a min-heap then pop the min element
// This doesn't use the fact that the sequences are sorted... possible to go
// faster? Time complexity: O(n log n)
//
// Yes, we can do better by limiting the size of the min-heap
// This is especially good if k << n
//
// Could also perform a merge sort on the files but that needs O(n) space

vector<int> merge_sorted_files(vector<vector<int>> &sequences) {
  priority_queue<int, vector<int>, greater<>> min_heap;

  for (const auto &sequence : sequences) {
    for (auto x : sequence) {
      min_heap.push(x);
    }
  }

  vector<int> result;
  while (!min_heap.empty()) {
    result.push_back(min_heap.top());
    min_heap.pop();
  }

  return result;
}

// A better solution
// Think about how I can create data types to store the information that I need
struct IteratorToEnd {
  bool operator>(const IteratorToEnd &that) const { return *curr > *that.curr; }
  vector<int>::const_iterator curr;
  vector<int>::const_iterator end;
};

vector<int> merge_sorted_arrays(vector<vector<int>> sorted_arrays) {
  priority_queue<IteratorToEnd, vector<IteratorToEnd>, greater<>> min_heap;

  for (const auto &array : sorted_arrays) {
    min_heap.emplace(IteratorToEnd{array.cbegin(), array.cend()});
  }

  vector<int> result;
  while (!min_heap.empty()) {
    auto &array = min_heap.top();
    min_heap.pop();

    if (array.curr != array.end) {
      result.push_back(*array.curr);
      min_heap.emplace(IteratorToEnd{next(array.curr), array.end});
    }
  }

  return result;
}
