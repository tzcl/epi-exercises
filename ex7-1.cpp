// Implement a method that takes a string representing an integer and returns
// the corresponding integer, and vice versa. Your code should handle negative
// integers. You cannot use library functions like stoi.
//
// Hint: build the result one digit at a time

#include <bits/stdc++.h>

// Assume input is not malformed
//
// More efficient to track the value of 10^i to avoid repeated calculations
int str_to_int(const std::string &a) {
  int result = 0;
  int power = 1;

  for (int i = a.size() - 1; i >= 0; i--) {
    const char &c = a[i];
    if (c == '-') {
      result *= -1;
    } else {
      // result += (c - '0') * pow(10, a.size() - 1 - i);
      result += (c - '0') * power;
      power *= 10;
    }
  }

  return result;
}

// A more elegant approach is to just multiply the result by 10 and add the
// digit
int str_to_int1(const std::string &a) {
  int result = 0;
  for (int i = a[0] == '-' ? 1 : 0; i < a.size(); i++) {
    result = (result * 10) + (a[i] - '0');
  }

  return a[0] == '-' ? -result : result;
}

// Couldn't work out how to reverse the int to save preappending to the str.
// Could have just done it and then reversed at the end.
// This is the best approach
std::string int_to_str(int num) {
  std::string result = "";
  bool is_negative = num < 0;

  while (num) {
    result += '0' + std::abs(num % 10);
    num /= 10;
  }

  if (is_negative) {
    result += '-';
  }

  return {result.rbegin(), result.rend()};
}

int main() {

  std::string a = "123";
  std::string b = "-33331";
  int c = 3592;
  int d = -325;

  std::cout << str_to_int1(a) << std::endl;
  std::cout << str_to_int1(b) << std::endl;
  std::cout << int_to_str(c) << std::endl;
  std::cout << int_to_str(d) << std::endl;

  return 0;
}
