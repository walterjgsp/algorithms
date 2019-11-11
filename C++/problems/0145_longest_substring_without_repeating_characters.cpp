// Problem Statement
// Given a string, find the length of the longest substring without repeating characters.

#include "0145_longest_substring_without_repeating_characters.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::lengthOfLongestSubstring(string s){
    queue<int> indexes;
        vector<int> count(256,0);
        int result = 0, window_size;
        
        for(int i=0;i<s.size();i++){
            int pos = s[i];
            while(!indexes.empty() && count[pos]>0){
                int front = indexes.front();
                count[s[front]]--;
                indexes.pop();
            }
            indexes.push(i);
            count[pos]++;
            window_size = indexes.size();
            result = max(result,window_size);            
        }
        
        window_size = indexes.size();
        result = max(result,window_size);            
        
        return result;
}