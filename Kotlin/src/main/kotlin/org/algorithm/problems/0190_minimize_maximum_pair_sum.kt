package org.algorithm.problems
// Problem Statement
// The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

// For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
// Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

// Each element of nums is in exactly one pair, and
// The maximum pair sum is minimized.
// Return the minimized maximum pair sum after optimally pairing up the elements.


class `0190_minimize_maximum_pair_sum` {
    fun minPairSum(nums: IntArray): Int {
        nums.sort()
        var result : Int = 0
        var start = 0
        var end = nums.size - 1;

        while(start < end){
            result = Math.max(result,nums[start]+nums[end])
            start++
            end--
        }

        return result
    }
}
