// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).

// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).

// How many possible unique paths are there?

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] grid = new int[m][n];
        fillFirstCases(grid);
        fillNextCases(grid);
        return grid[m - 1][n - 1];
    }

    private void fillFirstCases(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            grid[i][0] = 1;
        }
        for (int i = 0; i < grid[0].length; i++) {
            grid[0][i] = 1;
        }
    }

    private void fillNextCases(int[][] grid) {
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                int top = grid[i - 1][j];
                int left = grid[i][j - 1];
                grid[i][j] = top + left;
            }
        }
    }

}

class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int m = 3;
        int n = 7;
        System.out.println(sol.uniquePaths(m, n));
    }
}