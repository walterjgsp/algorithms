//Problem Statement
//Given an array consisting of n integers, find the contiguous
//subarray of given length k that has the maximum average value.
//And you need to output the maximum average value.
package org.algorithm.problems

class `0044_maximum_average_subarray_i` {
    fun findMaxAverage(nums: IntArray, k: Int): Double {
        var result: Double = Double.NEGATIVE_INFINITY;
        var actualSum: Double = 0.0;
        var start: Int = 0;
        var end: Int = 0;

        for (num in nums) {
            actualSum += num;
            end++;
            if (end - start == k) {
                var tempAvg: Double = 0.0;
                tempAvg = actualSum / k;
                result = maxOf(result, tempAvg);
                actualSum -= nums[start];
                start++;
            }
        }

        return result;
    }
}