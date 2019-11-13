// Problem Statement
// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

#include "0147_maximum_product_subarray.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maxProduct(vector<int> nums){
    int result = nums[0],max_val = nums[0], max_neg = nums[0];
    for(int i=1;i<nums.size();i++){
        int curr_val = nums[i];
        int old_max = max_val;
        max_val = max(curr_val,max(curr_val*max_val,curr_val*max_neg));
        max_neg = min(curr_val,min(curr_val*old_max,curr_val*max_neg));
        result = max(result,max_val);
    }
    
    return result;
}