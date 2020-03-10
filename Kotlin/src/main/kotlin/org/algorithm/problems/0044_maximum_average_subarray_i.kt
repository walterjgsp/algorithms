//Problem Statement
//Given an array consisting of n integers, find the contiguous
//subarray of given length k that has the maximum average value.
//And you need to output the maximum average value.

class Solution constructor() {
    fun findMaxAverage(nums: IntArray, k: Int): Double {
        var result:Double = Double.NEGATIVE_INFINITY;
        var actualSum:Double = 0.0;
        var start:Int = 0;
        var end:Int = 0;

        for(num in nums){
            actualSum+=num;
            end++;
            if(end-start==k){
                var tempAvg:Double = 0.0;
                tempAvg = actualSum/k;
                result = maxOf(result,tempAvg);
                actualSum-=nums[start];
                start++;
            }
        }

        return result;
    }
};

fun main(args:Array<String>){
  var vec:IntArray = intArrayOf(1,12,-5,-6,50,3);
  var k:Int = 4;
  var sol:Solution = Solution();

  println(sol.findMaxAverage(vec,k));
}
