// Problem Statement
// The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

// For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
// Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

// Each element of nums is in exactly one pair, and
// The maximum pair sum is minimized.
// Return the minimized maximum pair sum after optimally pairing up the elements.

#include "0190_minimize_maximum_pair_sum.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::minPairSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int result = 0, start = 0, end = nums.size()-1;
    while(start<end){
        result = max(result, nums[start]+nums[end]);
        start++, end--;
    }
    
    return result;
}