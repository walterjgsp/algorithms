//Problem Statement
// Given an undirected graph, return true if and only if it is bipartite.
//
// Recall that a graph is bipartite if we can split it's set of nodes into two
// independent subsets A and B such that every edge in the graph has one node in
// A and another node in B.
//
// The graph is given in the following form: graph[i] is a list of indexes j
// for which the edge between nodes i and j exists.  Each node is an integer
// between 0 and graph.length - 1.  There are no self edges or parallel edges:
// graph[i] does not contain i, and it doesn't contain any element twice.
package org.algorithm.problems

import java.util.ArrayDeque

class `0051_is_graph_bipartite` {
    fun isBipartite(graph: Array<IntArray>): Boolean {
        val colors = IntArray(graph.size) { -1 }
        val processed = mutableSetOf<Int>()
        val bfs = ArrayDeque<Int>()

        for (i in 0 until graph.size) {
            if (colors[i] == -1) {
                bfs.addLast(i)
                while (!bfs.isEmpty()) {
                    val curr = bfs.poll()
                    if (!processed.contains(curr)) {
                        processed.add(curr)

                        var curr_color = 0
                        if (colors[curr] != -1) {
                            curr_color = colors[curr]
                        }

                        colors[curr] == curr_color

                        val neigh_color = if (curr_color == 0) 1 else 0
                        for (neigh in graph[curr]) {
                            if (colors[neigh] == curr_color) {
                                return false
                            }
                            if (!processed.contains(neigh)) {
                                bfs.addLast(neigh)
                                colors[neigh] = neigh_color
                            }
                        }
                    }
                }
            }
        }
        return true
    }
}