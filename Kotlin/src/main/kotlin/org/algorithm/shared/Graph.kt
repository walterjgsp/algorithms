package org.algorithm.shared

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
}