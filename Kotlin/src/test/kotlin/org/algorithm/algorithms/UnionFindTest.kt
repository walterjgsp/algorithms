package org.algorithm.algorithms

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

class UnionFindTest {

    @Test
    fun testCreateInstance() {
        val unionFind = UnionFind(6)
        for (index in 0 until 6) {
            assertEquals(index, unionFind.find(index).first)
        }
    }

    @Test
    fun testSmallSet() {
        val unionFind = UnionFind(6)
        unionFind.union(0, 3)
        unionFind.union(1, 0)
        unionFind.union(4, 5)
        unionFind.union(2, 4)

        assertEquals(0, unionFind.find(3).first)
        assertEquals(0, unionFind.find(1).first)
        assertEquals(4, unionFind.find(5).first)
        assertEquals(4, unionFind.find(2).first)
    }
}