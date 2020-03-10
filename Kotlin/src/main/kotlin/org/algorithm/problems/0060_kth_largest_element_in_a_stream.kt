// Problem Statement
// Design a class to find the kth largest element in a stream.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Your KthLargest class will have a constructor which accepts an integer k and an
// integer array nums, which contains initial elements from the stream.
// For each call to the method KthLargest.add, return the element representing the
// kth largest element in the stream.
package org.algorithm.problems

import java.util.*;

class KthLargest(val k: Int, nums: IntArray) {

    private val pq = PriorityQueue<Int>()

    init{
        for(num in nums){
            if(pq.size>=k){
                if(pq.peek()<num){
                    pq.add(num)
                    pq.poll()
                }
            }else{
                pq.add(num)
            }
        }
    }

    fun add(value: Int): Int {
        if(pq.size>=k){
            if(pq.peek()<value){
                pq.add(value)
                pq.poll()
            }
        }else{
            pq.add(value)
        }
        return pq.peek();
    }
}

