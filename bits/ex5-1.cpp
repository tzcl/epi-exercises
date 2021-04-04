// Computing the parity of a word
//
// The parity of a binary word is 1 if the number of 1s in the word is odd;
// otherwise, it is 0. for example, the parity of 1011 is 1, and the parity of
// 10001000 is 0.
//
// How would you compute the parity of a very large number of 64-bit words?
//
// Hint: Use a lookup table, but don't use 2^64 entries.

#include <bits/stdc++.h>

// Calculating parity -- from ESD2
// Note that this is O(n) where n is the word size!
short check_parity(int num) {
  short parity = 0;
  while (num) {
    parity ^= num & 1;
    num >>= 1;
  }

  return parity;
}

// A more efficient algorithm works by only iterating over the number of bits in
// num that are 1
// This is O(s) where s is the number of bits that are 1 in num
short check_parity1(int num) {
  short parity = 0;
  while (num) {
    parity ^= 1;       // flip the parity bit
    num &= ~(num - 1); // drops the lowest set bit of num
  }

  return parity;
}

// How would I compute the parity of lots of big 64-bit words?
//
// I had no idea. Two keys to performance when performing any kind of
// bit-fiddling computations is to process multiple bits at a time and cache
// results in an array-based lookup table.

// Lookup table approach (caching)
//
// Caching every 64-bit integer is impossible. However, 16-bit integers is fine
// (2^16 = 65536). You precompute the possible values and then xor them
// together. The tricky bit is extracting the 16-bit sections from the 64-bit
// word (need to use bit-shifting and bitmasks).
// The complexity is O(n/L) where n is the word size and L is the cached word
// size.

// Processing multiple bits at a time
//
// With this problem, a key insight is to see that xor is associative and
// commutative. This means that if you have (11010111) you can calculate the
// parity by xoring (1101) and (0111). This is the same as xoring (11) and (01)
// and (01) and (11).
// This is O(log n) but is generally slower than caching in practice.

int main(int argc, char **argv) {
  int num;
  std::cout << "Enter a number: ";
  std::cin >> num;

  std::cout << "Parity: " << check_parity1(num) << std::endl;

  return 0;
}
