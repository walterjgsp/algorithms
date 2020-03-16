package org.algorithm.problems

import org.algorithm.shared.ListNode
import org.algorithm.shared.vecToLinkedList
import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

class `0003_add_two_numbers_test` {

    @Test
    fun test_equalSizeNumbers() {
        val vec1: IntArray = intArrayOf(2, 4, 3)
        val vec2: IntArray = intArrayOf(5, 5, 4)
        val list1: ListNode? = vec1.vecToLinkedList()
        val list2: ListNode? = vec2.vecToLinkedList()
        val solution = `0003_add_two_numbers`()
        assertEquals("797",solution.addTwoNumbers(list1,list2).toString())
    }

}