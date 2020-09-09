//Problem Statement
// Given a string s and an array of integers cost where cost[i] is 
// the cost of deleting the character i in s.

// Return the minimum cost of deletions such that there 
// are no two identical letters next to each other.

// Notice that you will delete the chosen characters at the same time, 
// in other words, after deleting a character, the costs of deleting other characters will not change.
#include "0176_min_deletion_avoid_repeting.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::minCost(string s, vector<int>& cost) {
    stack<pair<char,int>> helper;
    int result = 0;
    
    for(int i=0;i<s.size();i++){
        while(!helper.empty() && 
                s[i] == helper.top().first && 
                cost[i] >= helper.top().second){
            result+=helper.top().second;
            helper.pop();
        }
        
        if(!helper.empty() && helper.top().first == s[i]){
            result+=cost[i];
        }else{
            helper.push({s[i],cost[i]});
        }
    }
    
    return result;
}