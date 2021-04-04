// Compute x^y
//
// Write a program that takes a double x and an integer y and returns x^y.
// You can ignore overflow and underflow.

#include <bits/stdc++.h>
using namespace std;

// We can speed up exponentiation by using by powers of 2
// For example, 10.5^5 = 10.5^4 * 10.5^1
//
// Got confused, but the trick was just to count how many times we needed to
// square (i.e., just shift right)
// Would've helped to work through an example and also to not optimise too
// pre-maturely

double power(double x, int y) {
  double result = 1;
  long long exponent = y;

  if (y < 0) {
    exponent = -y, x = 1.0 / x;
  }

  while (exponent) {
    if (exponent & 1) {
      result *= x;
    }
    x *= x, exponent >>= 1;
  }

  return result;
}
