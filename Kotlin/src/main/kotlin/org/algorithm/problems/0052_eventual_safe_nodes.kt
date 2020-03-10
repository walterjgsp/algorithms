//Problem Statement
// In a directed graph, we start at some node and every turn, walk along a directed
// edge of the graph.  If we reach a node that is terminal
// (that is, it has no outgoing directed edges), we stop.
//
// Now, say our starting node is eventually safe if and only if we must eventually
// walk to a terminal node.  More specifically, there exists a natural number K so
// that for any choice of where to walk, we must have stopped at a terminal node in
// less than K steps.
//
// Which nodes are eventually safe?  Return them as an array in sorted order.
//
// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length
// of graph.  The graph is given in the following form: graph[i] is a list of labels
// j such that (i, j) is a directed edge of the graph.
package org.algorithm.problems

class `0052_eventual_safe_nodes` {

    val memo:HashMap<Int,Boolean> = HashMap<Int,Boolean>();

    fun eventualSafeNodes(graph: Array<IntArray>): List<Int> {
        val result:MutableList<Int> = mutableListOf<Int>();

        for(i in graph.indices){
            if(!memo.containsKey(i)){
                val visited:HashSet<Int> = HashSet<Int>();
                dfs(graph,i,visited);
            }

            if(memo[i]!!){
                result.add(i);
            }
        }

        return result;
    }

    fun dfs(graph:Array<IntArray>, vertex : Int, visited: HashSet<Int>) : Boolean{
        if(memo.containsKey(vertex))
            return memo[vertex]!!;

        if(visited.contains(vertex)){
            memo.put(vertex,false);
            return memo[vertex]!!;
        }

        visited.add(vertex);

        var isSafe:Boolean = true;

        for(neighbor in graph[vertex]){
            isSafe = isSafe && dfs(graph,neighbor,visited);
        }

        memo.put(vertex,isSafe);
        return memo[vertex]!!;
    }
}
