//Problem Statement
// In a given grid, each cell can have one of three values:
//
// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
//
// Return the minimum number of minutes that must elapse until no cell has a fresh orange.
// If this is impossible, return -1 instead.

import java.util.ArrayDeque

class Solution constructor() {

    private val walkMask:Array<Pair<Int,Int>> = arrayOf(Pair(0,1),Pair(1,0),Pair(-1,0),Pair(0,-1))

    fun canWalk(grid: Array<IntArray>,row :Int, col: Int, dir:Pair<Int,Int>) :Boolean{
        return row+dir.first>=0 && row+dir.first<grid.size && col+dir.second>=0 && col+dir.second<grid[0].size && grid[row+dir.first][col+dir.second]==1
    }

    fun orangesRotting(grid: Array<IntArray>): Int {
        var bfs:ArrayDeque<Pair<Int,Int>> = ArrayDeque<Pair<Int,Int>>()
        var result: Int = -1

        for(row in 0..grid.size-1){
            for(col in 0..grid[0].size-1){
                if(grid[row][col]==2){
                    bfs.add(Pair(row,col));
                }
            }
        }

        while(bfs.isNotEmpty()){
            var tam : Int = bfs.size;

            for(index in 0..tam-1){
                var coord:Pair<Int,Int> = bfs.pollFirst();
                for(dir in walkMask){
                    if(canWalk(grid,coord.first,coord.second,dir)){
                        val row = coord.first+dir.first
                        val col = coord.second+dir.second
                        grid[row][col]=2
                        bfs.add(Pair(row,col))
                    }
                }
            }

            result++
        }

        for(row in 0..grid.size-1){
            for(col in 0..grid[0].size-1){
                if(grid[row][col]==1){
                    return -1
                }
            }
        }

        if(result<0)
            return 0

        return result
    }
}

fun main(args:Array<String>){
  var grid:Array<IntArray> = arrayOf(intArrayOf(2,1,1),intArrayOf(1,1,0),intArrayOf(0,1,1));
  var sol: Solution = Solution()
  println(sol.orangesRotting(grid))
}
