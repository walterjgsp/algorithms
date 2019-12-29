// Problem Statement
// Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
// When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

// Notice that you can not jump outside of the array at any time
#include "0155_jump_game_iii.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Solution::canReach(vector<int>& arr, int start) {
    unordered_set<int> visited;
    
    queue<int> bfs;
    bfs.push(start);
    
    while(!bfs.empty()){
        auto curr = bfs.front();
        bfs.pop();
        
        if(arr[curr]==0) return true;
        
        if(visited.find(curr)==visited.end()){
            visited.insert(curr);
            
            int left = curr-arr[curr], right = curr+arr[curr];
            
            if(left>=0){
                if(arr[left]==0) return true;
                if(visited.find(left)==visited.end()) bfs.push(left);
            }
            
            if(right<arr.size()){
                if(arr[right]==0) return true;
                if(visited.find(right)==visited.end()) bfs.push(right);
            }
        }
    }
    
    return false;
}