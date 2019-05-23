// Problem Statement
// You are a professional robber planning to rob houses along a street. Each house
// has a certain amount of money stashed, the only constraint stopping you from
// robbing each of them is that adjacent houses have security system connected and
// it will automatically contact the police if two adjacent houses were broken
// into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each
// house, determine the maximum amount of money you can rob tonight without
// alerting the police.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.empty())
            return 0;

        if(nums.size()<2)
            return nums[0];

        vector<int> dp(nums.size()+1,0);

        dp[1]=nums[0],dp[2]=max(nums[1],dp[1]);

        for(int i=3;i<dp.size();i++){
            dp[i]=max(dp[i-1],nums[i-1]+max(dp[i-2],dp[i-3]));
        }

        return dp.back();
    }
};

int main(){
  vector<int> houses = {2,7,9,3,1};
  Solution sol;
  cout<<sol.rob(houses)<<endl;
  return 0
}
