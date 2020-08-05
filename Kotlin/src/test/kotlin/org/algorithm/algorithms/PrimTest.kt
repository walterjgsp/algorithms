package org.algorithm.algorithms

import org.algorithm.shared.Graph
import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.Test

class PrimTest {

    private lateinit var graph: Graph

    @BeforeEach
    fun init() {
        graph = Graph(6)
        graph.addEdge(0, 1, 1)
        graph.addEdge(0, 3, 4)
        graph.addEdge(0, 4, 3)
        graph.addEdge(1, 4, 2)
        graph.addEdge(1, 3, 4)
        graph.addEdge(2, 4, 4)
        graph.addEdge(2, 5, 5)
        graph.addEdge(3, 4, 4)
        graph.addEdge(4, 5, 7)
    }

    @Test
    fun testMinimumSpanningTree() {
        val primResult = Prim().minimumSpanningTree(graph)
        val result = primResult.sumBy { it.first }
        assertEquals(16, result)
    }
}