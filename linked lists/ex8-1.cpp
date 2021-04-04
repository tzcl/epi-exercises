// Write a program that takes two lists, assumed to be sorted, and returns their
// merge. The only field your program can change in a node is its next field.

#include <bits/stdc++.h>

template <typename T> struct ListNode {
  T data;
  std::shared_ptr<ListNode<T>> next;
};

// Hard to write real code for this without my own linked list implementation
// (C++'s forward_lists work differently to barebones linked lists)
//
// Had the right idea, for future questions, use the ListNode struct.
//
// The solution uses a clever idea. Just iterate over L1 && L2 and once you
// reach the end of one, just add the remaining list to the end (no need to
// process). This is O(n + m) in the worst case.
std::shared_ptr<ListNode<int>> merge(std::shared_ptr<ListNode<int>> &L1,
                                     std::shared_ptr<ListNode<int>> &L2) {
  std::shared_ptr<ListNode<int>> result(new ListNode<int>);
  auto tail = result;

  while (L1 && L2) {
    // append smaller node to result
    if (L1->data <= L2->data) {
      tail->next = L1;
      tail = L1;
      L1 = L1->next;
    } else {
      tail->next = L1;
      tail = L1;
      L1 = L1->next;
    }

    if (L1) {
      tail->next = L1;
    } else if (L2) {
      tail->next = L2;
    }

    return result->next;
  }

  return result->next;
}

int main() { return 0; }
