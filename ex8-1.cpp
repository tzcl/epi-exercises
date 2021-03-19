// Write a program that takes two lists, assumed to be sorted, and returns their
// merge. The only field your program can change in a node is its next field.

#include <bits/stdc++.h>

// Hard to write real code for this without my own linked list implementation
// (C++'s forward_lists work differently to barebones linked lists)
//
// Had the right idea, for future questions, use the ListNode struct.
//
// The solution uses a clever idea. Just iterate over L1 && L2 and once you
// reach the end of one, just add the remaining list to the end (no need to
// process). This is O(n + m) in the worst case.
std::forward_list<int> merge(std::forward_list<int> &L1,
                             std::forward_list<int> &L2) {
  std::forward_list<int> result;

  while (L1 || L2) {
    if (L1.data <= L2.data) {
      result->next = L1;
      if (L1->next)
        L1 = L1->next;
    } else {
      result->next = L2;
      if (L2->next)
        L2 = L2->next;
    }
  }

  return result;
}

int main() { return 0; }
