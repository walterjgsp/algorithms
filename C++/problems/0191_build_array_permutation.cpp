// Problem Statement
// Given a zero-based permutation nums (0-indexed), build an array ans of the same 
// length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

// A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

#include "0191_build_array_permutation.hpp"
#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::buildArray(vector<int>& nums){
    vector<int> result(nums.size());
        
    for(int i=0;i<nums.size();i++){
        result[i] = nums[nums[i]];
    }
    
    return result;
}