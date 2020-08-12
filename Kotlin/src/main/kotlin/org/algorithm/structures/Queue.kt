package org.algorithm.structures

import java.lang.StringBuilder

class Queue<T> {
    private data class Node<T>(
        val value: T,
        var next: Node<T>? = null
    )

    private var front: Node<T>? = null
    private var end: Node<T>? = null
    private var capacity: Int = 0
    val size: Int
        get() = capacity

    fun push(newValue: T) {
        val newNode = Node<T>(newValue)
        if (front == null) {
            front = newNode
        }

        end?.next = newNode
        end = newNode
        capacity++
    }

    fun peek(): T? {
        return front?.value
    }

    fun pop() {
        if (front != null) {
            front = front?.next

            if (front == null) {
                end = null
            }
            capacity--
        }
    }

    override fun toString() : String {
        var iterator: Node<T>? = front
        val builder = StringBuilder()
        while (iterator != null) {
            builder.append("${iterator.value} ")
            iterator = iterator.next
        }
        return builder.toString()
    }

    fun empty() = capacity == 0
}