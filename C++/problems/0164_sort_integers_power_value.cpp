// Problem Statement
// The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

// if x is even then x = x / 2
// if x is odd then x = 3 * x + 1
// For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

// Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by 
// the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

// Return the k-th integer in the range [lo, hi] sorted by the power value.

// Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 
// using these steps and that the power of x is will fit in 32 bit signed integer.

#include "0164_sort_integers_power_value.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::helperRecursive(int val, unordered_map<int,int> &memo){
    if(memo.find(val)==memo.end()){
        if(val == 1){
            memo[val] = 1;
        }else{
            int power;

            if(val%2==0){
                power = 1+helperRecursive(val/2,memo);
            }else{
                power = 1+helperRecursive(3*val+1,memo);
            }

            memo[val] = power;
        }
    }
    
    return memo[val];
}

int Solution::getKth(int lo, int hi, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    unordered_map<int,int> memo;
    
    for(int i=lo;i<=hi;i++){
        helperRecursive(i,memo);
        pq.push({memo[i],i});
    }
    
    while(k>1 && !pq.empty()){
        pq.pop();
        k--;
    }
    
    return pq.top().second;
}