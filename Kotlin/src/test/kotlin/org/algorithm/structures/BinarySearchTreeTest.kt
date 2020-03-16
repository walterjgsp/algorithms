package org.algorithm.structures

import org.junit.jupiter.api.Test

class BinarySearchTreeTest {

    @Test
    fun testBinarySearchTree_insert(){
        val binarySearchTree = BinarySearchTree()
        binarySearchTree.insert(5)
        assert(binarySearchTree.query(5,false))
    }
}