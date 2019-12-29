// Problem Statement
// Given a square array of integers A, we want the minimum sum of a falling path through A.

// A falling path starts at any element in the first row, and chooses one element from each row.  
// The next row's choice must be in a column that is different from the previous row's column by at most one.
#include "0154_minimum_falling_path_sum.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::minFallingPathSum(vector<vector<int>>& A){
    vector<vector<int>> dp(A.size(),vector<int>(A[0]));
    int result = INT_MAX;
    
    for(int j=0;j<A[0].size();j++){
        dp[0][j] = A[0][j];
    }
    
    for(int row = 1;row<A.size();row++){
        for(int col=0;col<A[0].size();col++){
            int curr_best = dp[row-1][col];
            if(col>0) curr_best = min(curr_best,dp[row-1][col-1]);
            if(col<A[0].size()-1) curr_best = min(curr_best,dp[row-1][col+1]);
            dp[row][col] = A[row][col]+curr_best;
        }
    }
    
    for(auto val : dp.back()){
        result = min(result,val);
    }
    
    return result;
}
 