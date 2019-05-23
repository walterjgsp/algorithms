// Problem Statement
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

class Solution {
    fun maxSubArray(nums: IntArray): Int {
        var actualSum:Int = nums[0];
        var maxSum:Int = nums[0];

        for(i in 1..nums.size-1){
            actualSum = maxOf(actualSum+nums[i],nums[i]);
            maxSum = maxOf(actualSum,maxSum);
        }

        return maxSum;
    }
}

fun main(args:Array<String>){
    var nums:IntArray = intArrayOf(-2,1,-3,4,-1,2,1,-5,4);
    var sol:Solution = Solution();

    println(sol.maxSubArray(nums));
}
