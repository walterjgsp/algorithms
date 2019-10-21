// Problem Statement
// You are given a map in form of a two-dimensional integer grid where 1 
// represents land and 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). 
// The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes" (water inside that isn't connected to the 
// water around the island). One cell is a square with side length 1. The grid is rectangular, 
// width and height don't exceed 100. Determine the perimeter of the island.

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int result;
    vector<int> dir = {0,1,0,-1};
    
    void bfs(vector<vector<int>> &grid, int row, int col){
        grid[row][col]=2;
        for(int i=0;i<4;i++){
            int new_row = row+dir[i];
            int new_col = col+dir[(i+1)%4];
            if(new_row>=0 && new_col>=0 && new_row<grid.size() && new_col<grid[0].size()){
                if(grid[new_row][new_col]==0){
                    result++;
                }else if(grid[new_row][new_col]==1){
                    bfs(grid,new_row,new_col);
                }
            }else{
                result++;
            }
        }
    }    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        result = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    bfs(grid,i,j);
                    return result;
                }
            }
        }
        
        return result;
    }
};