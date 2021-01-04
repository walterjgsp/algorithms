#ifndef N_QUEENS_HPP_INCLUDED
#define N_QUEENS_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    
    vector<string> createBoard(int n);
    
    bool checkColumn(const vector<string> &board,const int &row,const int & column);
    
    bool checkDiagonal(const vector<string> &board, const int &row, const int &column);
    
    bool checkIDiagonal(const vector<string> &board, const int &row, const int &column);
    
    void placeQueen(vector<string> board, int row);
public:
    vector<vector<string>> solveNQueens(int n);
};

#include "0182_n_queens.cpp"

#endif