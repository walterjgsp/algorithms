// Problem Statement
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?
#include "0178_unique_paths.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::uniquePaths(int m, int n){
    vector<vector<int>> dp(m,vector<int>(n,0));
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int top = 0,left = 0;
            if(i==0 && j==0) dp[i][j]=1;
            if(i!=0) dp[i][j] += dp[i-1][j];
            if(j!=0) dp[i][j] += dp[i][j-1];
        }
    }
    
    return dp.back().back();
}