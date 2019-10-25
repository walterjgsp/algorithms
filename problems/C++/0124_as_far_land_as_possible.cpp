// Problem Statement
// Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 
// represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

// The distance used in this problem is the Manhattan distance: the distance 
// between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// If no land or water exists in the grid, return -1.
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    pair<int,int> inf = {INT_MAX,INT_MAX};
    int result = -1;
    
    vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    bool isValidDir(const int&i, const int&j, const int &rows, const int &cols){
        return i>=0 && i<rows && j>=0 && j<cols;
    }
    
    int calcManhattan(const int&x1, const int &y1, const int&x2, const int &y2){
        return abs(x1-x2)+abs(y1-y2);
    }

    void evaluatePosition(const vector<vector<int>> &grid, vector<vector<pair<int,int>>> &memo, int i, int j, const int&rows, const int &cols){
        if(grid[i][j]==1){
            memo[i][j]=make_pair(i,j);
            result = max(result,0);
        }else{
            for(auto dir : dirs){
                int next_i = i+dir.first, next_j = j+dir.second;
                if(isValidDir(next_i,next_j,rows,cols) && memo[next_i][next_j]!=inf){
                    if(memo[i][j]==inf){
                        memo[i][j]=memo[next_i][next_j];
                    }else{
                        auto old_cell = memo[i][j], new_cell = memo[next_i][next_j];
                        int new_dist = calcManhattan(i,j,new_cell.first,new_cell.second);
                        int old_dist = calcManhattan(i,j,old_cell.first,old_cell.second);
                        if(new_dist<old_dist){
                            memo[i][j] = memo[next_i][next_j];
                        }
                    }
                }
            }
        }
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(),cols = grid[0].size();
        vector<vector<pair<int,int>>> memo(rows,vector<pair<int,int>>(cols,make_pair(INT_MAX,INT_MAX)));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                evaluatePosition(grid,memo,i,j,rows,cols);
            }
        }
        
        if(result == -1) return result;
        
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                evaluatePosition(grid,memo,i,j,rows,cols);
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                auto cell = memo[i][j];
                int dist = calcManhattan(i,j,cell.first,cell.second);
                result = max(dist,result);
            }
        }
        
        return result==0 ? -1 : result;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    Solution sol;
    cout<<sol.maxDistance(grid)<<endl;

    return 0;
}