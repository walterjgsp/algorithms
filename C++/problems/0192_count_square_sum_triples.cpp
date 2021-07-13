// Problem Statement
// A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 + b^2 = c^2.

// Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

#include "0192_count_square_sum_triples.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::countTriples(int n) {
    int result = 0;
    for(int i=n;i>0;i--){
        int j = 0, k = i-1;
        while(j<=k){
            int sqrC = pow(i,2);
            int sqrAB = pow(j,2) + pow(k,2);
            
            if(sqrC == sqrAB){
                result+=2;
                j++;
            }else if(sqrC < sqrAB){
                k--;
            }else{
                j++;
            }
        }
    }
    return result;
}