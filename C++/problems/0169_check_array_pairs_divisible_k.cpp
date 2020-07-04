// Problem Statement
// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return True If you can find a way to do that or False otherwise.
#include "0169_check_array_pairs_divisible_k.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Solution::canArrange(vector<int>& arr, int k){
    vector<int> freq (k+1,0);
        
    for(auto val : arr){
        int comp = ((val%k)+k)%k;
        if(freq[k-comp]>0){
            freq[k-comp]--;
        }else{
            if(comp == 0){
                freq[k-comp]++;
            }else{
                freq[comp]++;
            }
        }
    }
    
    for(auto it : freq){
        if(it > 0){
            return false;
        }
    }
    
    return true;
}