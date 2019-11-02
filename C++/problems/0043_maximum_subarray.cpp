// Problem Statement
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.
#include <bits/stdc++.h>

using namespace std;

class Solution{
  int maxSubArray(vector<int> &nums){

    int actual_sum = nums[0],max_sum = actual_sum;

    for(int i=1;i<nums.size();i++){
      actual_sum=max(nums[i],actual_sum+nums[i]);
      max = max(actual_sum,max_sum);
    }

    return max_sum;
  }
};

int main(){
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  Solution sol;
  cout<<sol.maxSubArray(nums)<<endl;
  return 0;
}
