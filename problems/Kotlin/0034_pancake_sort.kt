//Problem Statement
// Given an array A, we can perform a pancake flip:
// We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.
// We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
//
// Return the k-values corresponding to a sequence of pancake flips that sort A.
// Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

class Solution {
    fun pancakeSort(A: IntArray): List<Int> {
        val result = mutableListOf<Int>()
        
        for(i in A.size-1 downTo 1){
            var max_index = Pair(A[0],0)
            for(j in 1..i){
                if(max_index.first<A[j]){
                    max_index = Pair(A[j],j)
                }
            }
            
            if(max_index.second>0){
                A.reverse(0,max_index.second)
                result.add(max_index.second+1)    
            }
            A.reverse(0,i)
            result.add(i+1)
        }
        
        return result;
    }
    
    private fun IntArray.reverse(from: Int, until: Int){
        var start = from
        var end = until
        while(start<end){
            var temp = this[start]
            this[start] = this[end]
            this[end] = temp
            start+=1
            end -= 1
        }
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val arr = intArrayOf(10,5,1,6,3,8,2,4,7,9)
    println(sol.pancakeSort(arr).jointToString())
}