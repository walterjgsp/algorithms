//Problem Statement
// Given a binary tree with N nodes, each node has a different value from {1, ..., N}.
//
// A node in this binary tree can be flipped by swapping the left child and
// the right child of that node.
//
// Consider the sequence of N values reported by a preorder traversal starting from the root.
// Call such a sequence of N values the voyage of the tree.
//
// (Recall that a preorder traversal of a node means we report the current node's
// value, then preorder-traverse the left child, then preorder-traverse the right child.)
//
// Our goal is to flip the least number of nodes in the tree so that the voyage
// of the tree matches the voyage we are given.
// 
// If we can do so, then return a list of the values of all nodes flipped.
// You may return the answer in any order.
//
// If we cannot do so, then return the list [-1].
/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
package org.algorithm.problems

import org.algorithm.shared.TreeNode

class `0038_flip_binary_tree_to_match_preorder` {

    private val result = mutableListOf<Int>()
    private var index = 0

    fun flipMatchVoyage(root: TreeNode?, voyage: IntArray): List<Int> {
        val canFlip = flipHelper(root, voyage)
        return if (canFlip && index == voyage.size) {
            result
        } else {
            listOf(-1)
        }
    }

    private fun flipHelper(node: TreeNode?, voyage: IntArray): Boolean {
        if (node == null) {
            return true
        }

        if (node.`val` == voyage[index]) {
            index += 1

            if (node.left != null && node.right != null) {
                val left = node.left!!.`val`
                val right = node.right!!.`val`

                if (left != voyage[index]) {
                    if (right == voyage[index]) {
                        val temp = node.left
                        node.left = node.right
                        node.right = temp
                        result.add(node.`val`)
                    } else {
                        return false
                    }
                }

                return flipHelper(node.left, voyage) && flipHelper(node.right, voyage)
            } else if (node.left != null) {
                return flipHelper(node.left, voyage)
            } else if (node.right != null) {
                return flipHelper(node.right, voyage)
            }
            return true
        } else {
            return false
        }
    }
}