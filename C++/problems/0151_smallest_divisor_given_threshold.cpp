//Problem Statement
// Given an array of integers nums and an integer threshold, we will choose a positive 
// integer divisor and divide all the array by it and sum the result of the division. 
// Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// It is guaranteed that there will be an answer.
#include "0151_smallest_divisor_given_threshold.hpp"
#include <bits/stdc++.h>

using namespace std;


int Solution::getDiv(const int &quotient,const int &divisor){
    int result = quotient/divisor;
    return (quotient%divisor==0) ? result : result+1;
}

int Solution::getSum(const vector<int> &nums, const int &divisor){
    int sum = 0;
    for(auto num:nums){
        sum+=getDiv(num,divisor);
    }
        
    return sum;
}

int Solution::smallestDivisor(vector<int>& nums, int threshold){
    int start = 1, end = 0;
    for(auto num : nums){
        end = max(end, num);
    }
    int result = end;
    
    while(start<end){
        int divisor = start+(end-start)/2;
        int sum = getSum(nums,divisor);
        
        if(sum>threshold){
            start = divisor+1;                
        }else{
            result = min(result,divisor);
            end = divisor;
        }
    }
    
    return result;
}

