// Problem Statement

// Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
//
// After this process, we have some array B.
//
// Return the smallest possible difference between the maximum value of B and the minimum value of B.

class Solution {
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

fun main(args:Array<String>){
  val vec:IntArray = intArrayOf(1,3,6);
  val sol:Solution = Solution();

  println(sol.smallestRangeI(vec,3));
}
