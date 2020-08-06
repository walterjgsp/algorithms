package org.algorithm.shared

import kotlin.math.max
import kotlin.math.min

class Graph(val size: Int, private val undirected: Boolean = true) {
    private val adjList: List<MutableList<Pair<Int, Int>>> = List(size) { mutableListOf<Pair<Int, Int>>() }

    fun addEdge(from: Int, to: Int, weight: Int = 1) {
        adjList[from].add(Pair(to, weight))
        if (undirected) {
            adjList[to].add(Pair(from, weight))
        }
    }

    fun getChildren(vertex: Int): List<Pair<Int, Int>> {
        return adjList[vertex]
    }

    fun getAllEdges(): List<Edge> {
        return if (undirected) getAllEdgesUndirected() else getAllEdgesDirected()
    }

    private fun getAllEdgesUndirected(): List<Edge> {
        val unique = hashSetOf<Edge>()
        adjList.forEachIndexed { index, children ->
            children.forEach { vertex ->
                val edge = Edge(min(index, vertex.first), max(index, vertex.first), vertex.second)
                unique.add(edge)
            }
        }
        return unique.toList()
    }

    private fun getAllEdgesDirected(): List<Edge> {
        val edges = mutableListOf<Edge>()
        adjList.forEachIndexed { index, children ->
            children.forEach { vertex ->
                val edge = Edge(index, vertex.first, vertex.second)
                edges.add(edge)
            }
        }
        return edges
    }
}