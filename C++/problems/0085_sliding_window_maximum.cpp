// Problem Statement
// Given an array nums, there is a sliding window of size k which is moving from
// the very left of the array to the very right. You can only see the k numbers in
// the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> indexes;
        vector<int> result;

        for(int i=0;i<nums.size();i++){

            if(!indexes.empty() && indexes.front()<=i-k){
                indexes.pop_front();
            }
            while(!indexes.empty() && nums[i]>nums[indexes.back()]){
                indexes.pop_back();
            }
            indexes.push_back(i);

            if(i>=k-1){
                result.push_back(nums[indexes.front()]);
            }
        }

        return result;
    }
};

void printVec(const vector<int> &nums){
  for(auto val : nums){
    cout<<val<<" ";
  }
  cout<<endl;
}

int main(){
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  Solution sol;
  printVec(sol.maxSlidingWindow(nums,3));
  return 0;
}
