// Problem Statement
// Given a 2D grid consists of 0s (land) and 1s (water).  
// An island is a maximal 4-directionally connected group of 0s and a 
// closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

#include "0148_number_of_closed_islands.hpp"
#include <bits/stdc++.h>

using namespace std;

void Solution::bfs(vector<vector<int>> &grid, int row, int col, int value){
    if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return;
    if(grid[row][col]==1) return;
    
    grid[row][col] = value;
    
    for(int i=0;i<dir.size()-1;i++){
        bfs(grid,row+dir[i],col+dir[i+1],value);
    }
}

int Solution::closedIsland(vector<vector<int>>& grid){
    int result = 0;
    for(int j=0;j<grid[0].size();j++){
        if(grid[0][j]==0){
            bfs(grid,0,j,1);
        }
        
        if(grid[grid.size()-1][j]==0){
            bfs(grid,grid.size()-1,j,1);
        }
    }
    
    for(int i=0;i<grid.size();i++){
        if(grid[i][0]==0){
            bfs(grid,i,0,1);
        }
        
        if(grid[i][grid[0].size()-1]==0){
            bfs(grid,i,grid[0].size()-1,1);
        }
    }
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0){
                result++;
                bfs(grid,i,j,1);
            }
        }
    }
    
    return result;
}