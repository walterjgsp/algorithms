// Problem Statement

// Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
//
// After this process, we have some array B.
//
// Return the smallest possible difference between the maximum value of B and the minimum value of B.
package org.algorithm.problems

class `0026_smallest_range_i` {
    fun smallestRangeI(A: IntArray, K: Int): Int {
        var maxVal:Int = Int.MIN_VALUE;
        var minVal:Int = Int.MAX_VALUE;

        for(value in A){
            maxVal = maxOf(maxVal,value);
            minVal = minOf(minVal,value);
        }

        if(((maxVal-K)-(minVal+K))<=0){
            return 0;
        }else{
            return (maxVal-K)-(minVal+K);
        }
    }
}
