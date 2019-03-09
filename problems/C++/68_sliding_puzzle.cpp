//Problem Statement
// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and
// an empty square represented by 0.
//
// A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//
// Given a puzzle board, return the least number of moves required so that the state
// of the board is solved. If it is impossible for the state of the board to be solved, return -1.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> moves { {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4} };

public:
    string boardToString(vector<vector<int>> &board){
        string str_board = "";

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                str_board.push_back(board[i][j]+'0');
            }
        }

        return str_board;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string str_board = boardToString(board);
        unordered_set<string> visited;

        queue<string> bfs;
        bfs.push(str_board);

        int result = 0;
        while(!bfs.empty()){
            int tam = bfs.size();

            for(int i=0;i<tam;i++){
                string actual = bfs.front();
                bfs.pop();
                if(actual == "123450")
                    return result;

                int index = actual.find('0');

                for(auto move : moves[index]){
                    string prox = actual;
                    swap(prox[move],prox[index]);
                    if(visited.insert(prox).second)
                        bfs.push(prox);
                }
            }
            result++;
        }

        return -1;
    }
};

int main(){
  vector<vector<int>> board = {{4,1,2},{5,0,3}};
  Solution sol;
  cout<<sol.slidingPuzzle(board)<<endl;
  return 0;
}
