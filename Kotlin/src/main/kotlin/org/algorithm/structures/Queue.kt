package org.algorithm.structures

class Queue<T>{
    private data class Node<T>(
        val value : T,
        var next: Node<T>? = null
    )

    private var front:Node<T>? = null
    private var end:Node<T>? = null
    private var capacity:Int = 0

    fun push(newValue: T){
        val newNode = Node<T>(newValue)
        if(front==null){
            front = newNode
        }

        end?.next = newNode
        end = newNode
        capacity++
    }

    fun size() = capacity

    fun peek(): T?{
        return front?.value
    }

    fun pop(){
        if(front!=null){
            front = front?.next

            if(front==null){
                end = null
            }
            capacity--
        }
    }

    fun printQueue(){
        var iterator: Node<T>? = front
        while(iterator!=null){
            print("${iterator.value} ")
            iterator = iterator.next
        }
    }
}