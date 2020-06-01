// Problem Statement
// Given two strings S and T, return if they are equal when both are typed 
// into empty text editors. # means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.
#include "0168_backspace_string_compare.hpp"
#include <bits/stdc++.h>

using namespace std;

string Solution::buildString(const string &word){
    string result;

    for(auto c: word){
        if(c!='#'){
            result.push_back(c);
        }else if(!result.empty()){
            result.pop_back();
        }
    }

    return result;
}

bool Solution::backspaceCompare(string S, string T){
    return buildString(S) == buildString(T);
}