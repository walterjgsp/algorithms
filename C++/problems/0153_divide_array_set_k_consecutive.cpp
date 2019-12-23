// Problem Statement
// Given an array of integers nums and a positive integer k, find whether it's 
// possible to divide this array into sets of k consecutive numbers
// Return True if its possible otherwise return False.
#include "0153_divide_array_set_k_consecutive.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Solution::isPossibleDivide(vector<int>& nums, int k){
    map<int,int> counter;
        
    for(auto num : nums){
        counter[num]++;
    }
    
    while(!counter.empty()){
        auto curr = counter.begin();
        if(curr->second==0){
            counter.erase(counter.begin());
        }else{
            for(int i=0;i<k;i++){
                int curr_key = (curr->first)+i;
                if(counter.find(curr_key)!=counter.end() && counter[curr_key]>0){
                    counter[curr_key]--;
                }else{
                    return false;
                }
            }
        }
    }
    
    return true;
}