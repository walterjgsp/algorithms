

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