// Problem Statement
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
#include "0182_n_queens.hpp"
#include <bits/stdc++.h>

using namespace std;
    
vector<string> Solution::createBoard(int n){
    return vector<string>(n,string(n,'.'));
}
    
bool Solution::checkColumn(const vector<string> &board,const int &row,const int & column){
    for(int i=row;i>=0;i--){
        if(board[i][column]=='Q')
            return false;
    }
    return true;
}
    
bool Solution::checkDiagonal(const vector<string> &board, const int &row, const int &column){
    for(int i=row,j=column;i>=0 && j<board.size();i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
    
bool Solution::checkIDiagonal(const vector<string> &board, const int &row, const int &column){
    for(int i=row,j=column;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
    
void Solution::placeQueen(vector<string> board, int row){
    if(row>=board.size()){
        result.push_back(board);
        return;
    }
    
    for(int i=0;i<board.size();i++){
        if(checkColumn(board,row,i) && 
            checkDiagonal(board,row,i) && 
            checkIDiagonal(board,row,i)){
            board[row][i]='Q';
            placeQueen(board,row+1);
            board[row][i]='.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    result.clear();
    vector<string> board = createBoard(n);
    placeQueen(board,0);
    return result;
}