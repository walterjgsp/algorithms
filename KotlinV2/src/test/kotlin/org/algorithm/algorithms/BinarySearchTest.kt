package org.algorithm.algorithms

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

class BinarySearchTest {

    @Test
    fun testBinarySearch(){
        val arr:IntArray = intArrayOf(1,2,3,5,7,8,10)
        val binary_search:BinarySearch = BinarySearch()
        assertEquals(3,binary_search.binarySearch(arr,5))
    }
}