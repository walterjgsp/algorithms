//Problem Statement
// Given an array arr that is a permutation of [0, 1, ..., arr.length - 1],
// we split the array into some number of "chunks" (partitions), and individually
// sort each chunk.  After concatenating them, the result equals the sorted array.
//
// What is the most number of chunks we could have made?
package org.algorithm.problems

import java.util.ArrayDeque

class `0062_max_chunks_to_make_sorted` {
    fun maxChunksToSorted(arr: IntArray): Int {

        var sorted : ArrayDeque<Int> = ArrayDeque<Int>()
        var result : Int = 0

        for(pos in 0..arr.size-1){
            sorted.add(arr[pos])

            while(sorted.isNotEmpty() && sorted.getLast()<=pos){
                sorted.pollLast()
            }

            if(sorted.isEmpty()){
                result++
            }
        }

        return result
    }
}
