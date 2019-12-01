// Problem Statement
// You are given a map of a server center, represented as a m * n integer matrix grid, 
// where 1 means that on that cell there is a server and 0 means that it is no server. 
// Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server.
#include "0149_count_servers_communicate.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::countServers(vector<vector<int>>& grid) {
    vector<int> rows (grid.size(),0),cols(grid[0].size(),0);
    int result = 0;
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==1){
                rows[i]++;
                cols[j]++;
            }
        }
    }
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==1 && (rows[i]>1 || cols[j]>1)){
                result++;
            }
        }
    }
    
    return result;
}