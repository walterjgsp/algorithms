package org.algorithm.structures

class DoubleLinkedList<T>() {
    private data class Node<T>(var prev: Node<T>? = null, var next: Node<T>? = null, var value: T)

    private var head: Node<T>? = null
    private var tail: Node<T>? = null
    var size: Int = 0
        private set

    fun printList() {
        var it: Node<T>? = head
        println("Lista:")
        while (it != null) {
            print(it.value.toString() + " ")
            it = it.next
        }
        println()
    }

    fun pushFront(value: T) {
        val newNode = Node<T>(value = value)
        if (head == null) {
            head = newNode
            tail = head
        } else {
            newNode.next = head
            head?.prev = newNode
            head = newNode
        }
        size++
    }

    fun popFront() {
        var it: Node<T>? = head
        if (it != null) {
            size--
            it = it.next
            if (it == null)
                tail = it
            else {
                it.prev = null
            }
        }

        head = it
    }

    fun insertAt(value: T, index: Int) {
        if (index <= 0 || head == null) {
            pushFront(value)
        } else if (index >= size) {
            pushBack(value)
        } else {
            size++
            var it: Node<T>? = head
            var walk = index
            while (it?.next != null && walk > 1) {
                it = it?.next
                walk--
            }

            val newNode = Node<T>(value = value)

            newNode.next = it?.next
            it?.next = newNode
            newNode.prev = it
        }
    }

    fun pushBack(value: T) {
        val newNode = Node<T>(value = value)
        if (tail != null) {
            tail?.next = newNode
            newNode?.prev = tail
            tail = newNode
        } else {
            head = newNode
            tail = head
        }
        size++
    }

    fun popBack() {
        var it: Node<T>? = tail
        if (it != null) {
            size--
            it = it.prev
            if (it == null)
                head = it
            else {
                it.next = null
            }
        }

        tail = it
    }

    fun isEmpty(): Boolean {
        return size > 0
    }
}