// Problem Statement
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canWalk(int row, int col, vector<int> limits){
        return row>=limits[0] && row<limits[1] && col>=limits[2] && col<limits[3];
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        vector<int> limits = {0,matrix.size(),0,matrix[0].size()};
        vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<pair<int,int>> strech = {{0,1},{3,-1},{1,-1},{2,1}};
        int max_result_size = matrix.size()*matrix[0].size();
        int row = 0, col = 0,dir=0;

        while(result.size()<max_result_size){

            result.push_back(matrix[row][col]);

            while(result.size()<max_result_size && !canWalk(row+direction[dir].first,col+direction[dir].second,limits)){
                limits[strech[dir].first]+=strech[dir].second;
                dir = (dir+1)%direction.size();
            }

            row+=direction[dir].first;
            col+=direction[dir].second;
        }

        return result;
    }
};

void printVec(const vector<int> vec){
  for(auto val : vec){
    cout<<val<<" ";
  }
  cout<<endl;
}

int main(){
  vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  Solution sol;
  printVec(sol.spiralOrder(matrix));
  return 0;
}
