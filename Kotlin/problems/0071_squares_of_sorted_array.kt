//Problem Statement
// Given an array of integers A sorted in non-decreasing order,
// return an array of the squares of each number, also in sorted non-decreasing order.
import java.lang.Math;

class Solution constructor(){
    fun sortedSquares(A: IntArray): IntArray {
        var start: Int = 0
        var end: Int = A.size-1
        var index: Int = 0
        var result: IntArray = IntArray(A.size) { i-> 0}

        while(start<=end){
            if(Math.abs(A[start])<Math.abs(A[end])){
                result[index]=A[end]*A[end];
                end--;
            }else{
                result[index]=A[start]*A[start];
                start++;
            }
            index++;
        }

        result.reverse()

        return result;
    }
}

fun main(args:Array<String>){
  val arr:IntArray = intArrayOf(-7,-3,2,3,11)
  val sol:Solution = Solution()
  println(sol.sortedSquares(arr).joinToString())
}
