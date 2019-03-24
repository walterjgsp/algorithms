// Problem Statement

// Given an array nums of n integers, are there elements a, b, c in nums
// such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());

        int j,k,sum;
        for(int i=0;i<nums.size()-1;i++){
          j=i+1,k=nums.size()-1;
          while(j<k){
            sum = nums[i]+nums[j]+nums[k];
            if(sum==0){
              result.push_back({nums[i],nums[j],nums[k]});

              while(j<k && nums[j]==nums[j+1]) j++;
              while(j<k && nums[k]==nums[k-1]) k--;
            }

            if(sum>0) k--;
            else j++;
          }

          while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        }

        return result;
    }
};

void printVec(const vector<int> &vec){
  for(auto val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<int> input = {-1, 0, 1, 2, -1, -4};
  Solution sol;
  for(auto ans : sol.threeSum(input)){
    printVec(ans);
  }
  return 0;
}
