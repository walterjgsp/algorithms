package org.algorithm.algorithms

import org.algorithm.shared.Graph
import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.Test

class PrimTest {

    private var graph: Graph = Graph(6)
    private var graph2: Graph = Graph(7)

    init {
        graph.addEdge(0, 1, 1)
        graph.addEdge(0, 3, 4)
        graph.addEdge(0, 4, 3)
        graph.addEdge(1, 4, 2)
        graph.addEdge(1, 3, 4)
        graph.addEdge(2, 4, 4)
        graph.addEdge(2, 5, 5)
        graph.addEdge(3, 4, 4)
        graph.addEdge(4, 5, 7)

        graph2.addEdge(0, 3, 5);
        graph2.addEdge(0, 1, 7);
        graph2.addEdge(1, 2, 8);
        graph2.addEdge(1, 3, 9);
        graph2.addEdge(1, 4, 7);
        graph2.addEdge(2, 4, 5);
        graph2.addEdge(3, 4, 15);
        graph2.addEdge(3, 5, 6);
        graph2.addEdge(4, 5, 8);
        graph2.addEdge(4, 6, 9);
        graph2.addEdge(5, 6, 11);
    }

    @Test
    fun testMinimumSpanningTree() {
        val primResult = Prim.minimumSpanningTree(graph)
        val result = primResult.sumBy { it.first }
        assertEquals(16, result)
    }

    @Test
    fun testMinimumSpanningTreeGraph2() {
        val primResult = Prim.minimumSpanningTree(graph2)
        val result = primResult.sumBy { it.first }
        assertEquals(39, result)
    }
}