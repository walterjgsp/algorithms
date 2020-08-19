package org.algorithm.algorithms

import org.algorithm.shared.Edge
import org.algorithm.shared.Graph
import java.util.*

object Prim {

    fun minimumSpanningTree(graph: Graph, start: Int = 0): List<Triple<Int, Int, Int>> {
        val visited = mutableSetOf<Int>()
        val edges = mutableListOf<Triple<Int, Int, Int>>()
        val priorityQueue = PriorityQueue<Edge>()

        priorityQueue.addAll(graph.getChildren(0).map { Edge(start, it.first, it.second) })

        while (priorityQueue.isNotEmpty() && visited.size < graph.size) {
            val smallest = priorityQueue.poll()

            val currEdge = listOf(smallest.from, smallest.to)
            if (!visited.containsAll(currEdge)) {
                edges.add(smallest.toTriple())
                currEdge.forEach { vertex ->
                    if (!visited.contains(vertex)) {
                        for (edge in graph.getChildren(vertex)) {
                            priorityQueue.add(Edge(vertex, edge.first, edge.second))
                        }
                    }
                }
                visited.addAll(currEdge)
            }

        }

        return edges
    }
}