package org.algorithm.algorithms

import org.algorithm.shared.Edge
import org.algorithm.shared.Graph
import java.util.*

/**
 * Kruskal is an algorithm used to find the minimum-spanning-tree from a graph
 * Time Complexity: O(E log V)
 * Space Complexity: O(V+E)
 */
object Kruskal {

    fun minimumSpanningTree(graph: Graph): List<Triple<Int, Int, Int>> {
        val unionFind = UnionFind(graph.size)
        val priorityQueue = PriorityQueue<Edge>()
        val edges = mutableListOf<Triple<Int, Int, Int>>()
        priorityQueue.addAll(graph.getAllEdges())

        while (priorityQueue.isNotEmpty() && edges.size < graph.size) {
            val smaller = priorityQueue.poll()
            val fromParent = unionFind.find(smaller.from)
            val toParent = unionFind.find(smaller.to)
            if (fromParent != toParent) {
                edges.add(smaller.toTriple())
                unionFind.union(fromParent.first, unionFind.find(toParent.first).first)
            }
        }

        return edges
    }
}