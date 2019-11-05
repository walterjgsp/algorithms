// Problem Statement
//
// You have a total of n coins that you want to form in a staircase shape,
// where every k-th row must have exactly k coins.
//
// Given n, find the total number of full staircase rows that can be formed.
//
// n is a non-negative integer and fits within the range of a 32-bit signed integer.
// Example:
// n = 5
//
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤
// return 2.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int total_rows = 0;
        int coins_per_row = 1;

        while(n>=coins_per_row){
            total_rows++;
            n-=coins_per_row;
            coins_per_row++;
        }

        return total_rows;
    }
};

int main(){
  Solution sol;
  cout<<sol.arrangeCoins(8)<<endl;
  return 0;
}
