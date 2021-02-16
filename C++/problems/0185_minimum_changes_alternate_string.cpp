//Problem Statement
// You are given a string s consisting only of the characters '0' and '1'. 
// In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal. 
// For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.
#include "0185_minimum_changes_alternate_string.hpp"
#include <bits/stdc++.h>

using namespace std;

string Solution::createAlternate(int size, bool startZero){
    string result = "";
    for(int i=0;i<size;i++){
        if(startZero){
            result.push_back('0');
        }else{
            result.push_back('1');
        }
        startZero = !startZero;
    }
    return result;
}

int Solution::checkDiff(const string &w1, const string &w2){
    int diff = 0;
    for(int i=0;i<w1.size();i++){
        if(w1[i]!=w2[i]){
            diff++;
        }
    }
    return diff;
}

int Solution::minOperations(string s) {
    string s1 = createAlternate(s.size(),true), s2 = createAlternate(s.size(),false);
    
    return min(checkDiff(s1,s),checkDiff(s2,s));
}