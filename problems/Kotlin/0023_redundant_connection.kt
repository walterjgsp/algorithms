//Problem Statement
//
// In this problem, a tree is an undirected graph that is connected and has no cycles.
// The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N),
// with one additional edge added. The added edge has two different vertices chosen
// from 1 to N, and was not an edge that already existed.
//
// The resulting graph is given as a 2D-array of edges. Each element of edges is
// a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.
//
// Return an edge that can be removed so that the resulting graph is a tree of
// N nodes. If there are multiple answers, return the answer that occurs last in
// the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
class Solution {

    private lateinit var parent: IntArray
    
    private fun find(x : Int): Int{
        if(parent[x]==x){
            return x
        }
        return find(parent[x])
    }

    private fun Union(x: Int, y: Int) : Boolean{
        val xparent = find(x)
        val yparent = find(y)

        return if(xparent!=yparent){
            parent[yparent] = xparent
            true
        }else{
            false
        }
    }

    fun findRedundantConnection(edges: Array<IntArray>): IntArray {
        parent = IntArray(edges.size+1)
        for(i in 0 until parent.size){
            parent[i] = i
        }

        var result: IntArray = intArrayOf()

        for(edge in edges){
            if(!Union(edge[0],edge[1])){
                result = edge
            }            
        }

        return result;
    }
}

fun main(args: Array<String>) {
    val edges = arrayOf(intArrayOf(1,2),intArrayOf(2,3),intArrayOf(3,4),intArrayOf(1,4),intArrayOf(1,5))
    val sol = Solution()
    println(sol.findRedundantConnection(edges).joinToString())
}