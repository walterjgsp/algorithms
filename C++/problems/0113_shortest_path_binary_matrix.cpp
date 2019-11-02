// Problem Statement
// In an N by N square grid, each cell is either empty (0) or blocked (1).

// A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

// Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
// C_1 is at location (0, 0) (ie. has value grid[0][0])
// C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
// If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
// Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    bool canWalk(const int &row, const int &col, const vector<vector<int>>& grid){
        return row>=0 && col>=0 && row<grid.size() && col<grid[0].size();
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> memo (grid.size(),vector<int>(grid[0].size(),-1));
        
        queue<pair<int,int>> bfs;
        bfs.push({0,0});
        int depth = 1;
        
        while(!bfs.empty() && memo.back().back()==-1){
            
            int tam = bfs.size();
            for(int i=0;i<tam;i++){
                auto curr = bfs.front();
                int row = curr.first, col = curr.second;
                bfs.pop();
                if(grid[row][col]==0 && memo[row][col]==-1){
                    memo[row][col]=depth;
                    
                    for(auto dir : directions){
                        if(canWalk(row+dir.first, col+dir.second,grid)){
                            bfs.push({row+dir.first,col+dir.second});
                        }
                    }
                }
            }
            
            depth++;
        }
        
        return memo.back().back();
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    Solution sol;
    cout<<sol.shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}