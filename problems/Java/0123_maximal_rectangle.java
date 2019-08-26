//Problem Statement
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
import java.util.ArrayList;
import java.util.Stack;

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        char grid[][] = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        System.out.println(sol.maximalRectangle(grid));
    }
}

class Solution {

    private int maxAreaRow(int[] row){
        Stack<Integer> indices = new Stack<Integer>();
        int result = 0;

        for(int i=0;i<row.length;i++){
            while(!indices.empty() && row[indices.peek()]>=row[i]){
                int height = row[indices.peek()];
                indices.pop();

                int area = 0;
                if(indices.empty()){
                    area = height * i;
                }else{
                    area = height * (i-indices.peek()-1);
                }

                result = Math.max(area,result);
            }
            indices.push(i);
        }

        while(!indices.empty()){
            int height = row[indices.peek()];
            indices.pop();

            int area = 0;
            if(indices.empty()){
                area = height * row.length;
            }else{
                area = height * (row.length - indices.peek() - 1);
            }

            result = Math.max(area, result);
        }

        return result;
    }

    public int maximalRectangle(char[][] matrix) {
        if(matrix.length==0 || matrix[0].length==0){
            return 0;
        }

        int result = 0;
        int histo [][] = new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                histo[i][j]=0;
            }
        }

        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]=='1'){
                    if(i>0){
                        histo[i][j] = histo[i-1][j]+1;
                    }else{
                        histo[i][j] = 1;
                    }
                }
            }
        }

        for(int i=0;i<matrix.length;i++){
            int curr_rect = maxAreaRow(histo[i]);
            result = Math.max(curr_rect,result);
        }

        return result;
    }
}