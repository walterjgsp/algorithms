// Problem Statement

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> index_val;
      index_val[nums[0]]=0;
      vector<int> result;
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
};

void printVec(vector<int> vec){
  for(auto val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  Solution sol;
  vector<int> vec = {2, 11, 7, 15};
  printVec(sol.twoSum(vec,9));
  return 0;
}
