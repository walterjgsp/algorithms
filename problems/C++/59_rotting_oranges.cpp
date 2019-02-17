//Problem Statement
// In a given grid, each cell can have one of three values:
//
// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
//
// Return the minimum number of minutes that must elapse until no cell has a fresh orange.
// If this is impossible, return -1 instead.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int,int>> walkMask = {{0,1},{0,-1},{1,0},{-1,0}};
public:

    bool canWalk(int row, int col, vector<vector<int>> &grid, pair<int,int> dir){
        return row+dir.first>=0 && row+dir.first<grid.size() && col+dir.second>=0 && col+dir.second<grid[0].size() && grid[row+dir.first][col+dir.second]==1;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> bfs;
        int result=-1;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2)
                    bfs.push(make_pair(i,j));
            }
        }

        while(!bfs.empty()){
            int tam = bfs.size();

            for(int i=0;i<tam;i++){

                auto rotten = bfs.front();
                bfs.pop();

                for(auto dir: walkMask){
                    int row = rotten.first, col = rotten.second;
                    if(canWalk(row, col, grid,dir)){
                        grid[row+dir.first][col+dir.second]=2;
                        bfs.push(make_pair(row+dir.first,col+dir.second));
                    }
                }
            }

            result++;
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }


        return result>=0 ? result : 0 ;
    }
};

int main(){

  vector<vector<int>> grid = {{2,1,1},{2,1,0},{0,1,1}};
  Solution sol;
  cout<<sol.orangesRotting(grid)<<endl;

  return 0;
}
