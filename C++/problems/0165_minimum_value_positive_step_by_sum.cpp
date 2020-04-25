// Problem Statement
// Given an array of integers nums, you start with an initial positive value startValue.

// In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

// Return the minimum positive value of startValue such that the step by step sum is never less than 1.

#include "0165_minimum_value_positive_step_by_sum.hpp"
#include <bits/stdc++.h>

int Solution::minStartValue(vector<int>& nums){
    int result = 1, curr_prefix=0;
    for(auto num : nums){
        curr_prefix+=num;
        result = min(result,curr_prefix);
    }
    
    if(result<=0){
        result = -result+1;
    }
    
    return result;
}