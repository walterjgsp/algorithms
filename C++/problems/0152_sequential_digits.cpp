//Problem Statement
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
#include "0152_sequential_digits.hpp"
#include <bits/stdc++.h>

using namespace std;

void Solution::helperBack(vector<int> &result, int last_digit,int curr_value, const int &low, const int &high){
    if(curr_value>high){
        return;
    }
    
    if(curr_value>=low){
        result.push_back(curr_value);
    }
    
    if(last_digit!=9){
        curr_value= curr_value * 10 + last_digit+1;
        helperBack(result,last_digit+1,curr_value,low,high);
    }
}
vector<int> Solution::sequentialDigits(int low, int high) {
    vector<int> result;
    for(int i=1;i<10;i++){
        helperBack(result,i,i,low,high);
    }
    sort(result.begin(),result.end());
    return result;
}