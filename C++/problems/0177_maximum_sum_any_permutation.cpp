// Problem statement

// We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. 
// The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. 
// Both starti and endi are 0-indexed.

// Return the maximum total sum of all requests among all permutations of nums.

// Since the answer may be too large, return it modulo 10^9 + 7.
#include "0177_maximum_sum_any_permutation.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests){
    vector<int> freq(nums.size());

    int mod=1000000007;
    
    for(auto req : requests){
        freq[req[0]]++;
        if(req[1]<nums.size()-1){
            freq[req[1]+1]--;
        }
    }
    
    for(int i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
    }

    sort(nums.begin(),nums.end(),greater<int>());
    sort(freq.begin(),freq.end(),greater<int>());
    
    int result=0;

    for (int i=0;i<freq.size();i++){
       result=(result+(freq[i]*nums[i])%mod)%mod;
    }
        
    return result;
}