package org.algorithm.algorithms

import org.algorithm.shared.Graph
import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

class DijkstraTest {

    private var graph: Graph = Graph(9)

    init {
        graph.addEdge(0, 1, 4);
        graph.addEdge(0, 7, 8);
        graph.addEdge(1, 7, 11);
        graph.addEdge(1, 2, 8);
        graph.addEdge(2, 8, 2);
        graph.addEdge(2, 3, 7);
        graph.addEdge(2, 5, 4);
        graph.addEdge(3, 5, 14);
        graph.addEdge(3, 4, 9);
        graph.addEdge(4, 5, 10);
        graph.addEdge(5, 6, 2);
        graph.addEdge(6, 7, 1);
        graph.addEdge(6, 8, 6);
        graph.addEdge(7, 8, 7);
    }

    @Test
    fun testMinPath() {
        val result = intArrayOf(0, 4, 12, 19, 21, 11, 9, 8, 14)
        val dijkstraResult = Dijkstra.minPath(graph,0)
        assertEquals(dijkstraResult.joinToString(),result.joinToString())
        assertEquals(result.sum(),dijkstraResult.sum())
    }
}