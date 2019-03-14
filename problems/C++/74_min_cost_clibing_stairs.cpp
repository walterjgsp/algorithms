//Problem Statement
// On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
//
// Once you pay the cost, you can either climb one or two steps. You need to find
// minimum cost to reach the top of the floor, and you can either start from the
// step with index 0, or the step with index 1.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size(),0);
        dp[0]=cost[0],dp[1]=cost[1];

        for(int i=2;i<dp.size();i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return dp.back();
    }
};

int main(){
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  Solution sol;
  cout<<sol.minCostClimbingStairs(cost)<<endl;
  return 0;
}
