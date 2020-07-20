// Problem Statement
// Given an array of integers nums.

// A pair (i,j) is called good if nums[i] == nums[j] and i < j.

// Return the number of good pairs.

#include "0170_number_of_good_pairs.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::numIdenticalPairs(vector<int>& nums){
    unordered_map<int,int> pairs_count;
    int result = 0;
    for(auto val : nums){
        pairs_count[val]++;
    }
    
    for(auto it : pairs_count){
        result+= ((it.second-1)*(it.second))/2;
    }
    
    return result;
}