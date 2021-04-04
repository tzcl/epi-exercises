// Write a program that takes text for an anonymous letter and text for a
// magazine and determines if it is possible to write the anonymous letter using
// the magazine.
//
// The anonymous letter can be written using the magazine if for each character
// in the anonymous letter, the number of times it appears in the anonymous
// letter is no more than the number of times it appears in the magazine.

#include <bits/stdc++.h>
using namespace std;

// Assume input is two strings
// Brute force solution is to count character frequencies for the
// letter/magazine and compare them
// Is it possible to do any better? Another approach could be to sort the two
// strings but that could be expensive if the strings are long
// Is it possible to using caching?

// Time complexity of O(m) where m is the length of magazine
bool can_construct_letter(const string &letter, const string &magazine) {
  unordered_map<char, int> magazine_freq;

  for (char c : magazine) {
    ++magazine_freq[c];
  }

  for (char c : letter) {
    // not quite right
    int &freq = magazine_freq[c];
    if (freq == 0)
      return false;
    --freq;
  }

  return true;
}

// I came up with the right approach but had bugs in my code. Need to check if a
// key is in the map before subscripting. Also, it's more efficient to construct
// the character set from the letter!
bool can_construct_letter2(const string &letter, const string &magazine) {
  unordered_map<char, int> letter_freq;

  for (char c : letter) {
    ++letter_freq[c];
  }

  for (char c : magazine) {
    auto it = letter_freq.find(c);
    if (it != letter_freq.end()) {
      --it->second;

      if (it->second == 0) {
        letter_freq.erase(it);
        if (letter_freq.empty())
          break;
      }
    }
  }
  return letter_freq.empty();
}
