// Problem Statement
// In a given 2D binary array A, there are two islands.
// (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
//
// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
//
// Return the smallest number of 0s that must be flipped.
// (It is guaranteed that the answer is at least 1.)
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int,int>> steps = {{-1,0},{1,0},{0,1},{0,-1}};
    int row_max,col_max;
public:

    bool canWalk(const int &row, const int &col, const pair<int,int> step){
        return row+step.first>=0 && row+step.first<row_max && col+step.second>=0 && col+step.second<col_max;
    }

    void markIsland(vector<vector<int>> &grid, int row, int col){
        if(grid[row][col]==2 || grid[row][col]==0)
            return;

        grid[row][col]=2;

        for(auto step : steps){
            if(canWalk(row,col,step)){
                markIsland(grid,row+step.first,col+step.second);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& A) {
        row_max = A.size();
        col_max = A[0].size();

        bool isMarked=false;
        for(int i=0;i<row_max;i++){
            for(int j=0;j<col_max;j++){
                if(A[i][j]==1){
                    markIsland(A,i,j);
                    isMarked = true;
                    break;
                }
            }

            if(isMarked)
                break;
        }

        queue<pair<pair<int,int>,int>> bfs;
        for(int i=0;i<row_max;i++){
            for(int j=0;j<col_max;j++){
                if(A[i][j]==2){
                   bfs.push(make_pair(make_pair(i,j),0));
                }
            }
        }

        int result=INT_MAX;
        while(!bfs.empty()){
            auto actual = bfs.front();
            bfs.pop();

            int row = actual.first.first;
            int col = actual.first.second;
            int cost = actual.second;
            bool resultFound = false;
            for(auto step : steps){
                if(canWalk(row,col,step)){
                    if(A[row+step.first][col+step.second]==1){
                        result = cost;
                        resultFound = true;
                        break;
                    }else if(A[row+step.first][col+step.second]==0){
                        A[row+step.first][col+step.second]=2;
                        bfs.push(make_pair(make_pair(row+step.first,col+step.second),cost+1));
                    }
                }
            }

            if(resultFound)
                break;
        }

        return result;

    }
};

int main(){
  vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
  Solution sol;
  cout<<sol.shortestBridge(grid)<<endl;
  return 0;
}
