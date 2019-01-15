//Problem Statement
//Given an array consisting of n integers, find the contiguous
//subarray of given length k that has the maximum average value.
//And you need to output the maximum average value.

#include <bits/stdc++.h>

using namespace std;

class Solution{
  double findMaxAverage(vector<int>& nums, int k) {
    double maxAverage=INT_MIN,actualAverage=0.0;
    int count=0;

    for(int i=0;i<nums.size();i++){
        if(count<k){
            actualAverage+=nums[i];
            count++;
        }else{
            maxAverage = max(maxAverage,actualAverage/k);
            actualAverage+=nums[i];
            actualAverage-=nums[i-k];
        }

    }

    maxAverage = max(maxAverage,actualAverage/k);

    return maxAverage;
  }
};

int main(){
  vector<int> vec = {1,12,-5,-6,50,3};
  Solution sol;
  cout<<sol.findMaxAverage(vec,4)<<endl;
  return 0;
}
