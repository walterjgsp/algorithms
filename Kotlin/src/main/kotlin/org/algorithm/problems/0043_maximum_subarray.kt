// Problem Statement
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.
package org.algorithm.problems

class `0043_maximum_subarray` {
    fun maxSubArray(nums: IntArray): Int {
        var actualSum: Int = nums[0];
        var maxSum: Int = nums[0];

        for (i in 1..nums.size - 1) {
            actualSum = maxOf(actualSum + nums[i], nums[i]);
            maxSum = maxOf(actualSum, maxSum);
        }

        return maxSum;
    }
}