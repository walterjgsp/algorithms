package org.algorithm.algorithms

import org.algorithm.shared.Edge
import org.algorithm.shared.Graph
import java.util.*

object Dijkstra {

    fun minPath(graph: Graph, start: Int): IntArray {
        val minPath = IntArray(graph.size) { Int.MAX_VALUE }
        val visited = hashSetOf<Int>()

        val priorityQueue = PriorityQueue<Edge>()

        priorityQueue.add(Edge(start, start, 0))

        while (priorityQueue.isNotEmpty()) {
            val currEdge = priorityQueue.poll()

            minPath[currEdge.to] = minOf(minPath[currEdge.to], currEdge.weight)
            visited.add(currEdge.to)
            for (children in graph.getChildren(currEdge.to)) {
                if (!visited.contains(children.first)) {
                    priorityQueue.add(Edge(currEdge.to, children.first, children.second + minPath[currEdge.to]))
                }
            }
        }

        return minPath
    }
}