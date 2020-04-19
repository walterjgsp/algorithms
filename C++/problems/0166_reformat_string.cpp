// Problem Statement
// Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

// You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. 
// That is, no two adjacent characters have the same type.

// Return the reformatted string or return an empty string if it is impossible to reformat the string.

#include "0166_reformat_string.hpp"
#include <bits/stdc++.h>

string Solution::reformat(string s){
    stack<char> letters, digit;
        
    for(auto c : s){
        if(isdigit(c)){
            digit.push(c);
        }else{
            letters.push(c);
        }
    }
    
    bool addDigit = digit.size() > letters.size();
    string result;
    
    while(!digit.empty() || !letters.empty()){
        if(addDigit){
            if(digit.empty()) return "";
            
            result.push_back(digit.top());
            digit.pop();
        }else{
            if(letters.empty()) return "";
            
            result.push_back(letters.top());
            letters.pop();
        }
        
        addDigit = !addDigit;
    }
    
    return result;
} 