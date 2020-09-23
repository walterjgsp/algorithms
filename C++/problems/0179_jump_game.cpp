// Problem Statement
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.
#include "0179_jump_game.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Solution::canJump(vector<int>& nums){
    int maxReach = 0;
    for(int i=0;i<nums.size();i++){
        maxReach = max(maxReach,i+nums[i]);
        if(maxReach>=nums.size()-1)
            return true;
        if(maxReach<=i)
            return false;
    }
    
    return false;
}