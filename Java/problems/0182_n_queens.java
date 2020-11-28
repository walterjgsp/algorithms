//Problem Statement
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<Integer>> boards = new ArrayList<>();
        solveNQueens(n, 0, new ArrayList<Integer>(), boards);
        return writeBoardAsStrings(boards);
    }

    private void solveNQueens(int n, int row, List<Integer> colPlacements,
                              List<List<Integer>> boards){
        if(row == n){
            boards.add(new ArrayList<>(colPlacements));
        } else {
            for(int col = 0; col < n; col++){
                colPlacements.add(col);
                // If is valid, choose position and check next row
                if(isValid(colPlacements)){
                    solveNQueens(n, row+1, colPlacements, boards);
                }
                // backtracks choices to find next valid combination
                colPlacements.remove(colPlacements.size()-1);
            }
        }
    }

    private boolean isValid(List<Integer> colPlacements){
        int rowId = colPlacements.size()-1;
        for(int i = 0; i<rowId; i++){
            int diff = Math.abs(colPlacements.get(rowId)-colPlacements.get(i));
            // Check if column has a queen or meets a diagonal
            if(diff == 0 || diff == rowId-i){
                return false;
            }
        }
        return true;
    }

    private List<List<String>> writeBoardAsStrings(List<List<Integer>> boards){
        List<List<String>> result = new ArrayList<>();

        for(List<Integer> validBoard : boards){

            List<String> currentBoard = new ArrayList<>();
            for(int queenPosition : validBoard){
                StringBuilder sb = new StringBuilder();
                for(int j=0; j<validBoard.size(); j++){
                    if(j == queenPosition){
                        sb.append("Q");
                    } else {
                        sb.append(".");
                    }
                }
                currentBoard.add(sb.toString());
            }
            result.add(currentBoard);
        }

        return result;
    }
}

class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 4;
        System.out.println(sol.solveNQueens(4));
    }
}