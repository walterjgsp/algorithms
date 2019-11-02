// Problem Statement

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include "0001_two_sum.hpp"
#include "bits/stdc++.h"

using namespace std;

Solution::Solution(){}

vector<int> Solution::twoSum(vector<int> nums, int target) {
  unordered_map<int,int> index_val;
  vector<int> result;

  if(nums.empty())
    return result;

  index_val[nums[0]]=0;
  for(int i=1;i<nums.size();i++){
    if(index_val.find(target-nums[i])!=index_val.end()){
      result.push_back(index_val[target-nums[i]]);
      result.push_back(i);
      break;
    }
    index_val[nums[i]]=i;
  }

  return result;
}