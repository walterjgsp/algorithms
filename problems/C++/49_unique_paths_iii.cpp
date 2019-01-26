//Problem Statement
// On a 2-dimensional grid, there are 4 types of squares:
//
// * 1 represents the starting square.  There is exactly one starting square.
// * 2 represents the ending square.  There is exactly one ending square.
// * 0 represents empty squares we can walk over.
// * -1 represents obstacles that we cannot walk over.
//
// Return the number of 4-directional walks from the starting square to the ending
// square, that walk over every non-obstacle square exactly once.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int result;
    vector<pair<int,int>> mask = {{1,0},{-1,0},{0,-1},{0,1}};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        result = 0;
        int walkable_squares = 0;
        pair<int,int> start;
        set<pair<int,int>> visited;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                switch(grid[i][j]){
                    case 0:
                        walkable_squares++;
                        break;
                    case 1:
                        start = make_pair(i,j);
                        walkable_squares++;
                        break;
                }
            }
        }

        dfs(grid,walkable_squares,start,visited);

        return result;
    }

    void dfs(vector<vector<int>> &grid, const int &walkable_squares,pair<int,int> square,
            set<pair<int,int>> &visited){

        if(grid[square.first][square.second]==-1)
            return;

        if(grid[square.first][square.second]==2){
            if(visited.size()==walkable_squares)
                result++;
            return;
        }

        if(visited.find(square)!=visited.end()){
            return;
        }

        visited.insert(square);
        int row = square.first, col = square.second;

        for(auto path : mask){
            if(row+path.first<0 || row+path.first >=grid.size() || col+path.second<0 || col+path.second >= grid[row].size())
                continue;
            dfs(grid,walkable_squares,make_pair(row+path.first,col+path.second),visited);
        }

        visited.erase(square);


    }
};

int main(){
  vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
  Solution sol;
  cout<<sol.uniquePathsIII(grid)<<endl;
  return 0;
}
