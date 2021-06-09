package org.algorithm.problems

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

class `0190_minimize_maximum_pair_sum_test` {

    @Test
    fun test1(){
        val solution = `0190_minimize_maximum_pair_sum`()
        assertEquals(solution.minPairSum(intArrayOf(3,5,3,2)),7)
    }

    @Test
    fun test2(){
        val solution = `0190_minimize_maximum_pair_sum`()
        assertEquals(solution.minPairSum(intArrayOf(3,5,4,2,4,6)),8)
    }
}
