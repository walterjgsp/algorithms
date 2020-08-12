// Problem Statement
// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array.

// Return 0 if there is no such subarray.

#include "0171_longest_subarray_deleting_one.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::longestSubarray(vector<int>& nums){
    vector<int> freq;
    int result = 0, count = 1;
    
    if(nums[0]==0){
        count = -1;
    }
    
    for(int i=1;i<nums.size();i++){
        if(nums[i]==0){
            if(count<0){
                count--;
            }else{
                freq.push_back(count);
                count=-1;
            }
        }else{
            if(count>0){
                count++;
            }else{
                freq.push_back(count);
                count=1;
            }
        }
    }
    
    freq.push_back(count);
    
    if(freq.size() == 1){
        return max(0,freq[0]-1);
    }
    
    for(int i=0;i<freq.size();i++){
        if(freq[i]>0){
            int withDeletion = 0;
            if(i>=2 && freq[i-1]>=-1){
                withDeletion = freq[i-2];
            }
            result = max(result,freq[i]+withDeletion);
        }
    }
    
    return result;
}
