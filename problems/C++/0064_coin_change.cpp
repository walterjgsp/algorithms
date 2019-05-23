//Problem statement
// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());

        vector<int> dp (amount+1,-1);
        dp[0]=0;

        for(int i=1;i<dp.size();i++){
            int index = 0;
            int minCoins = -1;
            while(index<coins.size() && coins[index]<=i){
                int quant = dp[i-coins[index]];
                index++;
                if(quant==-1)
                    continue;
                if(minCoins==-1)
                    minCoins = quant+1;
                else
                    minCoins = min(minCoins,quant+1);

            }

            dp[i]=minCoins;
        }

        return dp.back();
    }
};

int main(){
  vector<int> coins = {1,2,5};
  int target = 11;
  Solution sol;

  cout<<sol.coinChange(coins,target)<<endl;
  return 0;
}
