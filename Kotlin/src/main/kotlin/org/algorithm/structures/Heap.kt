package org.algorithm.structures

class Heap<T:Comparable<T>>(val isMinHeap : Boolean = false){

    private val heap: MutableList<T> = mutableListOf<T>()

    private fun heapifyUp(index : Int){
        if(index>=0){
            val parent: Int = (index-1)/2
            if(heap[index]>heap[parent]){
                heap.swap(index,parent)
                heapifyUp(parent)
            }
        }
    }

    private fun heapifyDown(index : Int){
        if(index<heap.size){
            val left = 2*index+1
            val right = 2*index+2

            val children = mutableListOf<Pair<T,Int>>()

            if(left<heap.size){
                children.add(Pair(heap[left],left))
            }

            if(right<heap.size){
                children.add(Pair(heap[right],right))
            }

            if(!children.isEmpty()){
                var swapIndex = 0
                for(i in 1 until children.size){
                    if(children[swapIndex].first < children[i].first){
                        swapIndex = i
                    }
                }

                val toHeapify = children[swapIndex].second
                if(heap[toHeapify]>heap[index]){
                    heap.swap(index,toHeapify);
                    heapifyDown(toHeapify);
                }
            }
        }
    }

    fun printHeap(){
        println(heap)
    }

    fun push(value : T){
        heap.add(value)
        heapifyUp(heap.size-1)
    }

    fun peek() : T{
        return heap.first()
    }

    fun isEmpty() : Boolean{
        return heap.isEmpty()
    }

    fun pop(){
        if(!heap.isEmpty()){
            heap.removeAt(0)
            if(heap.isNotEmpty()){
                heapifyDown(0)
            }
        }
    }

    fun <T> MutableList<T>.swap(index1: Int, index2: Int) {
        val tmp = this[index1]
        this[index1] = this[index2]
        this[index2] = tmp
    }
}