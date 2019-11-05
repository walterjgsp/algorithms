//Problem Statement
// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
//
// Each person may dislike some other people, and they should not go into the same group.
//
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
//
// Return true if and only if it is possible to split everyone into two groups in this way.
import java.util.ArrayDeque

class Solution {
    fun possibleBipartition(N: Int, dislikes: Array<IntArray>): Boolean {
        val graph = Array<MutableList<Int>>(N){mutableListOf<Int>()}
        val colors = IntArray(N){-1}
        
        for(dis in dislikes){
            graph[dis[0]-1].add(dis[1]-1)
            graph[dis[1]-1].add(dis[0]-1)
        }
        
        for(i in 0 until N){
            if(colors[i]==-1){
                val bfs = ArrayDeque<Int>()
                
                bfs.push(i)
                colors[i] = 1
                while(!bfs.isEmpty()){
                    val curr = bfs.pop()
                    for(son in graph[curr]){
                        if(colors[son]!=-1){
                            if(colors[son]==colors[curr]){
                                return false
                            }
                        }else{
                            colors[son]= if(colors[curr]==1) 2 else 1
                            bfs.push(son)
                        }
                    }
                }
            }
        }
        
        return true;
    }
}

fun main(args: Array<String>) {
    val dislikes = arrayOf<IntArray>(intArrayOf(1,2),intArrayOf(2,3),intArrayOf(2,4))
    val sol = Solution()
    println(sol.possibleBipartition(4,dislikes))

}