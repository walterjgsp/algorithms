// Problem Statement
// Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.

// Build the target array using the following operations:

// Push: Read a new element from the beginning list, and push it in the array.
// Pop: delete the last element of the array.
// If the target array is already built, stop reading more elements.
// You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.

// Return the operations to build the target array.

// You are guaranteed that the answer is unique.

#include "0167_build_array_stack_operations.hpp"
#include <bits/stdc++.h>

using namespace std;

vector<string> Solution::buildArray(vector<int>& target, int n){
    vector<string> result;
        
    int index = 0,curr_value=1;
    while(index<target.size()){
        result.push_back("Push");
        if(curr_value<target[index]){
            result.push_back("Pop");
        }else{
            index++;
        }
        
        curr_value++;
    }
    
    return result;
}