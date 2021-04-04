// My implementation of a max_heap
//
// Key operations: heapify, eject

#include <bits/stdc++.h>
using namespace std;

// Move item at index i up to its correct position O(log n)
void siftUp(vector<int> &nums, int i) {
  if (i == 0) // can't sift up root
    return;

  int parent = (i - 1) / 2;
  if (nums[parent] < nums[i]) { // min heap: nums[parents] > nums[i]
    swap(nums[parent], nums[i]);
    siftUp(nums, parent);
  }
}

// Move item at index i down to its correct position O(log n)
void siftDown(vector<int> &nums, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  int child = nums[left] > nums[right] ? left : right;

  if (nums[i] < nums[child]) {
    swap(nums[i], nums[child]);
    siftDown(nums, child);
  }
}

void buildHeap(vector<int> &nums) {
  for (int i = nums.size() / 2; i >= 0; i--) {
    siftDown(nums, i);
  }
}

void heapify(vector<int> &nums) {
  for (int i = nums.size() / 2; i >= 0; --i) {
    int parent = i;
    int parent_val = nums[parent]; // need to store this value
    bool heap = false;
    while (!heap && 2 * parent + 2 <= nums.size()) {
      // get the larger child
      int child = 2 * parent + 1;
      if (nums[child] <
          nums[child + 1]) { // min heap: select the smallest child
        ++child;
      }

      // compare against value of parent
      if (parent_val < nums[child]) { // min heap: swap this
        nums[parent] = nums[child];
        parent = child;
      } else {
        heap = true;
      }
    }
    nums[parent] = parent_val;
  }
}

int eject(vector<int> &heap) {
  int result = heap[0];
  heap[0] = heap[heap.size() - 1];
  heapify(heap);
  heap.pop_back();
  return result;
}

int main() {
  vector<int> test = {1, 16, 5, 30, 27, 17, 20, 2, 57, 3, 90};
  vector<int> test2(test);

  // compare heapify against library methods
  heapify(test);

  for (auto i : test) {
    cout << i << " ";
  }
  cout << boolalpha << is_heap(test.begin(), test.end());
  cout << endl;

  cout << "Ejecting: " << eject(test) << endl;
  for (auto i : test) {
    cout << i << " ";
  }
  cout << boolalpha << is_heap(test.begin(), test.end());
  cout << endl;

  make_heap(test2.begin(), test2.end());
  for (auto i : test2) {
    cout << i << " ";
  }
  cout << boolalpha << is_heap(test2.begin(), test2.end());
  cout << endl;
}
