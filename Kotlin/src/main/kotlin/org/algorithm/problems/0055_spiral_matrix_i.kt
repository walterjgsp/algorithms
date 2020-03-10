// Problem Statement
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
package org.algorithm.problems

class `0055_spiral_matrix_i`{

    fun canWalk(row:Int,col:Int,limits:IntArray) : Boolean {
        return row>=limits[0] && row<limits[1] && col>=limits[2] && col<limits[3];
    }

    fun spiralOrder(matrix: Array<IntArray>): List<Int> {
        var result:MutableList<Int> = mutableListOf<Int>();
        if(matrix.isEmpty())
            return result;

        var limits:IntArray = intArrayOf(0,matrix.size,0,matrix[0].size);
        var directions:Array<Pair<Int,Int>> = arrayOf<Pair<Int,Int>>(Pair(0,1),Pair(1,0),Pair(0,-1),Pair(-1,0));
        var strech:Array<Pair<Int,Int>> = arrayOf<Pair<Int,Int>>(Pair(0,1),Pair(3,-1),Pair(1,-1),Pair(2,1));
        var row:Int = 0;
        var col:Int = 0;
        var dir:Int = 0;
        var maxResultSize: Int = matrix.size * matrix[0].size;

        while(result.size < maxResultSize){
            result.add(matrix[row][col]);

            while(result.size < maxResultSize && !canWalk(row+directions[dir].first,col+directions[dir].second,limits)){
                limits[strech[dir].first]+=strech[dir].second;
                dir = (dir+1)%directions.size;
            }

            row+=directions[dir].first;
            col+=directions[dir].second;
        }

        return result;

    }
};

