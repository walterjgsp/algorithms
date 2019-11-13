// Problem Statement
// Given a string s of '(' , ')' and lowercase English characters. 

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the 
// resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

//     It is the empty string, contains only lowercase characters, or
//     It can be written as AB (A concatenated with B), where A and B are valid strings, or
//     It can be written as (A), where A is a valid string.

#include "0146_minimum_remove_valid_parentheses.hpp"
#include <bits/stdc++.h>

using namespace std;

string Solution::minRemoveToMakeValid(string s) {
    stack<int> indexes;
    string result;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='('){
            indexes.push(i);
        }else if(s[i]==')'){
            if(!indexes.empty() && s[indexes.top()]=='('){
                    indexes.pop();
            }else{
                indexes.push(i);
            }
        }
    }
    
    for(int i=s.size()-1;i>=0;i--){
        if(!indexes.empty() && indexes.top()==i){
            indexes.pop();
        }else{
            result.push_back(s[i]);
        }
    }
    
    reverse(result.begin(),result.end());
    return result;
}