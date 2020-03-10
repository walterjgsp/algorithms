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
package org.algorithm.problems

class `0049_unique_paths_iii` {
    
    private val visited = mutableSetOf<Int>()
    private var result = 0
    private var walkableSquares = 0
    private val dir = intArrayOf(0,1,0,-1)
    
    fun uniquePathsIII(grid: Array<IntArray>): Int {
        var start_row = 0
        var start_col = 0
        for(i in 0 until grid.size){
            for(j in 0 until grid[0].size){
                if(grid[i][j]==0){
                    walkableSquares+=1
                }
                if(grid[i][j]==1){
                    start_row = i
                    start_col = j
                    walkableSquares+=1
                }
            }
        }
        
        dfs(grid,start_row,start_col)
        return result
    }
    
    private fun dfs(grid: Array<IntArray>, row: Int, col:Int){
        val newKey = row*grid[0].size+col
        if(row<0 || col<0 || row>=grid.size || col>=grid[0].size || grid[row][col]==-1 || visited.contains(newKey)){
            return
        }
        
        if(grid[row][col]==2){
            if(walkableSquares==visited.size){
                result+=1
            }
            return
        }
        
        visited.add(newKey)
        
        for(i in 0 until 4){
            dfs(grid,row+dir[i],col+dir[(i+1)%4])
        }
        
        visited.remove(newKey)
    }
}
