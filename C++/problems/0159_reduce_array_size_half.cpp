// Problem Statement
// Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

// Return the minimum size of the set so that at least half of the integers of the array are removed.

#include "0159_reduce_array_size_half.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::minSetSize(vector<int>& arr){
    unordered_map<int,int> counter;
    int half_size = arr.size()/2,result = 0;
    
    for(auto val: arr){
        counter[val]++;
    }
    
    priority_queue<int> pq;
    
    for(auto it: counter){
        pq.push(it.second);
    }
    
    while(half_size>0){
        auto biggest = pq.top();
        pq.pop();
        
        half_size-=biggest;
        result++;
    }
    
    return result;
}