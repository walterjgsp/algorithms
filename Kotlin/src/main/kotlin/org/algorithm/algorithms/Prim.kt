package org.algorithm.algorithms

import org.algorithm.shared.Graph
import java.util.*

class Prim {

    private data class Edge(val from: Int, val to: Int, val weight: Int) : Comparable<Edge> {
        override fun compareTo(other: Edge): Int {
            return weight.compareTo(other.weight)
        }

        fun toTriple(): Triple<Int, Int, Int> {
            return Triple(weight, from, to)
        }
    }

    fun minimumSpanningTree(graph: Graph, start: Int = 0): List<Triple<Int, Int, Int>> {
        val visited = mutableSetOf<Int>()
        val edges = mutableListOf<Triple<Int, Int, Int>>()
        val priorityQueue = PriorityQueue<Edge>()

        for (edge in graph.getChildren(start)) {
            priorityQueue.add(Edge(start, edge.first, edge.second))
        }

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