// Design a stack that includes a max operation, in addition to push and pop.
// the max method should return the maximum value stored in the stack.
//
// Hint: use additional storage to track the maximum value.

#include <bits/stdc++.h>
using namespace std;

// What does design a stack mean? Implement a stack?
// Doing these problems is annoying without boilerplate code.

// This is very much C code, I should've made a Stack class

// This is a good approach but there is a way to improve further.
// There is wasted space if you insert an element that is smaller than max, so
// instead you should have another stack that tracks max and frequency
// This gives the same worst-case but better best-case
struct TrackMax {
  int val;
  int max;
};

void insert(stack<TrackMax> &s, int val) {
  int max = val;
  if (!s.empty()) {
    max = std::max(max, s.top().max);
  }
  s.push({val, max});
}

int stack_max(stack<TrackMax> &s) { return s.top().max; }

class Stack {
public:
  Stack() {}

  bool empty() const { return s.empty(); }

  void push(int e) {
    if (aux.empty()) {
      aux.emplace(MaxCache{e, 1});
    } else {
      MaxCache &cache_top = aux.top();
      if (e == cache_top.max) {
        cache_top.count++;
      } else if (e > cache_top.max) {
        aux.emplace(MaxCache{e, 1});
      }
    }

    s.push(e);
  }

  void pop() {
    if (s.empty() || aux.empty())
      throw length_error("Stack is empty!");

    MaxCache &cache_top = aux.top();
    if (s.top() == cache_top.max) {
      cache_top.count--;

      if (cache_top.count == 0) {
        aux.pop();
      }
    }

    s.pop();
  }

  int top() {
    if (s.empty())
      throw length_error("Stack is empty!");
    return s.top();
  }

  int max() const {
    if (empty()) {
      throw length_error("max(): empty stack");
    }
    return aux.top().max;
  }

private:
  stack<int> s;

  // Could use a first but this lets you name the members
  struct MaxCache {
    int max;
    int count;
  };

  stack<MaxCache> aux;
};

int main() {
  stack<TrackMax> s;

  insert(s, 10);
  insert(s, 5);
  insert(s, 20);
  s.pop();

  cout << stack_max(s) << endl;
}
