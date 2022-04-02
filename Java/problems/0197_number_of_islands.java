// Problem Statement
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

import java.util.Set;
import java.util.HashSet;

class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;

        for (int column = 0; column < grid.length; column++) {
            for (int row = 0; row < grid[column].length; row++) {
                if (isLand(grid, column, row)) {
                    markIslandBorders(grid, column, row);
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isLand(char[][] grid, int column, int row) {
        return grid[column][row] == '1';
    }

    // DFS
    private void markIslandBorders(char[][] grid, int column, int row) {

        if (!isLand(grid, column, row)) {
            return;
        }

        // mark visited
        grid[column][row] = 'V';

        // is not first column
        if (column != 0) {
            // goUp
            markIslandBorders(grid, column - 1, row);
        }

        // is not last column
        if (column + 1 < grid.length) {
            // goDown
            markIslandBorders(grid, column + 1, row);
        }

        // is not first row
        if (row != 0) {
            // goLeft
            markIslandBorders(grid, column, row - 1);
        }

        // is not last column
        if (row + 1 < grid[column].length) {
            // goRight
            markIslandBorders(grid, column, row + 1);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        char[][] gridOneIsland = {
                { '1', '1', '1', '1', '0' },
                { '1', '1', '0', '1', '0' },
                { '1', '1', '0', '0', '0' },
                { '0', '0', '0', '0', '0' }
        };

        char[][] gridThreeIslands = {
                { '1', '1', '0', '0', '0' },
                { '1', '1', '0', '0', '0' },
                { '0', '0', '1', '0', '0' },
                { '0', '0', '0', '1', '1' }
        };

        System.out.println(solution.numIslands(gridOneIsland));
        System.out.println(solution.numIslands(gridThreeIslands));
    }
}
