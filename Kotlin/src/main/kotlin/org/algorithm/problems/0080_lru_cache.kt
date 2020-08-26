//Problem Statement
// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its
// capacity, it should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
package org.algorithm.problems

class LRUCache(val capacity: Int) {

    data class Node(
            val key: Int,
            val value: Int
    )

    private val lru = mutableListOf<Node>()

    private fun removeFirst() {
        lru.removeAt(0)
    }

    private fun addNode(key: Int, value: Int) {
        lru.add(Node(key, value));
    }

    fun get(key: Int): Int {
        val index = lru.indexOfFirst { it.key == key }
        if (index == -1) {
            return -1
        } else {
            val it = lru[index]
            lru.removeAt(index)
            addNode(it.key, it.value)
            return it.value
        }
    }

    fun put(key: Int, value: Int) {
        val index = lru.indexOfFirst { it.key == key }
        if (index != -1) {
            lru.removeAt(index)
        } else if (lru.size >= capacity) {
            removeFirst()
        }

        addNode(key, value)
    }

    fun printCache() {
        println(lru)
    }
}

fun main() {
    val cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.printCache()
    println(cache.get(1))
    cache.put(3, 3)
    cache.printCache()
}