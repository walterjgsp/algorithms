// Problem Statement
// There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

// * In each step, you will choose any 3 piles of coins (not necessarily consecutive).
// * Of your choice, Alice will pick the pile with the maximum number of coins.
// * You will pick the next pile with maximum number of coins.
// * Your friend Bob will pick the last pile.
// * Repeat until there are no more piles of coins.

// Given an array of integers piles where piles[i] is the number of coins in the ith pile.
// Return the maximum number of coins which you can have.
#include "0174_maximum_number_coins.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maxCoins(vector<int> &piles){
    sort(piles.begin(),piles.end());
    int result = 0;
    
    int i=0,k = piles.size()-2;
    
    while(i<k){
        result+=piles[k];
        i++;
        k-=2;
    }
    
    return result;
}
