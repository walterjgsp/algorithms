// Problem Statement
//
// You have a total of n coins that you want to form in a staircase shape,
// where every k-th row must have exactly k coins.
//
// Given n, find the total number of full staircase rows that can be formed.
//
// n is a non-negative integer and fits within the range of a 32-bit signed integer.
// Example:
// n = 5
//
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤
// return 2.

class Solution {
    fun arrangeCoins(n: Int): Int {
        var row:Int = 1;
        var result:Int = 0;
        var coins:Int = n;

        while(coins>=row){
            result++;
            coins-=row;
            row++;
        }

        return result;
    }
}

fun main( args : Array<String> ){
  val n:Int = 8;
  val sol:Solution = Solution();
  println(sol.arrangeCoins(n));
}
