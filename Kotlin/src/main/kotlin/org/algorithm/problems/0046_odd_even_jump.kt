// Problem Statement

// You are given an integer array A.  From some starting index, you can make a
// series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called odd
// numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.
//
// You may from index i jump forward to index j (with i < j) in the following way:
//
// *During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j
//   such that A[i] <= A[j] and A[j] is the smallest possible value.
//   If there are multiple such indexes j, you can only jump to the smallest such index j.
// *During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j
//   such that A[i] >= A[j] and A[j] is the largest possible value.
//   If there are multiple such indexes j, you can only jump to the smallest such index j.
// *(It may be the case that for some index i, there are no legal jumps.)
//
// A starting index is good if, starting from that index, you can reach the end of
// the array (index A.length - 1) by jumping some number of times (possibly 0 or more than once.)
//
// Return the number of good starting indexes.
package org.algorithm.problems

class BST {
    data class Node(
            var value: Int,
            var index: Int,
            var left: Node? = null,
            var right: Node? = null
    )

    private var root: Node? = null

    fun add(value: Int, index: Int) {
        if (root == null) {
            root = Node(value, index)
        } else {
            var it = root

            while (it != null) {
                if (it.value == value) {
                    it.index = index
                    break
                } else if (it.value < value) {
                    if (it.right == null) {
                        it.right = Node(value, index)
                        break
                    } else {
                        it = it.right
                    }
                } else {
                    if (it.left == null) {
                        it.left = Node(value, index)
                        break
                    } else {
                        it = it.left
                    }
                }
            }
        }
    }

    fun getMaxSmallest(value: Int): Int? {
        var it = root
        var curr: Node? = null
        while (it != null) {
            if (it.value <= value) {
                curr = it
                it = it.right
            } else {
                it = it.left
            }
        }
        return curr?.index
    }

    fun getMinBiggest(value: Int): Int? {
        var it = root
        var curr: Node? = null
        while (it != null) {
            if (it.value >= value) {
                curr = it
                it = it.left
            } else {
                it = it.right
            }
        }
        return curr?.index
    }
}

class `0046_odd_even_jump` {
    fun oddEvenJumps(A: IntArray): Int {
        val bst = BST()
        var result = 0
        val oddJump = IntArray(A.size) { 0 }
        val evenJump = IntArray(A.size) { 0 }

        oddJump[A.size - 1] = 1
        evenJump[A.size - 1] = 1
        bst.add(A[A.size - 1], A.size - 1)

        for (i in A.size - 2 downTo 0) {
            val indexOdd = bst.getMinBiggest(A[i])
            val indexEven = bst.getMaxSmallest(A[i])

            indexEven?.let {
                evenJump[i] = oddJump[indexEven]
            }

            indexOdd?.let {
                oddJump[i] = evenJump[indexOdd]
            }
            bst.add(A[i], i)
        }

        for (jump in oddJump) {
            result += jump
        }

        return result
    }
}