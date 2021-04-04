// Buy and sell a stock once
//
// Write a program that takes an array denoting the daily stock price, and
// returns the maximum profit that could be made by buying and then selling one
// share of that stock.

#include <bits/stdc++.h>

// For example, [310,315,275,295,260,270,290,230,255,250]
// the max profit is 30: buy at 260, sell at 290
// This is kind of like a dp problem(?)

// First idea, traverse the array and find the min before i --> O(n^2)
// (you have to buy before you can sell)
//
// Second idea, traverse once but track smallest so far --> O(n)
// Is this called Kadane's algorithm? Kadane's algorithm is for max subarray

int max_profit(std::vector<int> A) {
  int min_so_far = A[0];
  int profit = 0;
  for (int price : A) {
    min_so_far = std::min(min_so_far, price);
    profit = std::max(profit, price - min_so_far);
  }

  return profit;
}

int main() {
  std::vector<int> A = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};

  std::cout << max_profit(A) << std::endl;

  return 0;
}
