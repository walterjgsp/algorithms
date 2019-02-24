//Problem statement
// You are given coins of different denominations and a total amount of money.
// Write a function to compute the number of combinations that make up that amount.
// You may assume that you have infinite number of each kind of coin.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount+1,0);
        dp[0]=1;

        for(auto coin : coins){
            for(int change=coin;change<=amount;change++){
                dp[change]+=dp[change-coin];
            }
        }

        return dp.back();
    }
};

int main(){
  vector<int> coins = {1,2,5};
  int target = 5;
  Solution sol;

  cout<<sol.change(target,coins)<<endl;

  return 0;
}
