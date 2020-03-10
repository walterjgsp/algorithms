package org.algorithm.problems

import org.hamcrest.CoreMatchers.hasItems
import org.hamcrest.MatcherAssert.assertThat
import org.junit.jupiter.api.Test

class `0001_two_sum_test` {

    @Test
    fun testTwoSum_smallEntry(){
        val nums: IntArray = intArrayOf(2, 7, 11, 15)
        val target = 9
        val solution = `0001_two_sum`()

        assertThat(solution.twoSum(nums,target).asList(),hasItems(0,1))
    }
}