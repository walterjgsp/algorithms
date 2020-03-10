// Problem Statement
// We are given a binary tree (with root node root), a target node, and an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the
// target node.  The answer can be returned in any order.

/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
package org.algorithm.problems

import org.algorithm.shared.TreeNode

class `0048_all_nodes_distance_k_in_binary_tree` {
    
    private val parents = HashMap<Int, TreeNode?>()
    private var targetFound = false
    private val result = mutableListOf<Int>()
    private val visited = mutableSetOf<Int>()
    
    fun distanceK(root: TreeNode?, target: TreeNode?, K: Int): List<Int> {
        if(K!=0){
            parents.put(root!!.`val`,null)
            findTarget(root,target);
            populateResult(target,0,K)
        }else{
            result.add(target!!.`val`)
        }
        
        return result
    }
    
    private fun populateResult(node: TreeNode?, currDist: Int, K: Int){
        if(node==null){
            return 
        }
        
        visited.add(node.`val`)
        
        if(currDist==K){
            result.add(node.`val`)
        }else{
            if(node.left!=null && !visited.contains(node.left?.`val`)){
                populateResult(node.left,currDist+1,K)
            }
            
            if(node.right!=null && !visited.contains(node.right?.`val`)){
                populateResult(node.right,currDist+1,K)
            }
            
            val parent = parents.get(node.`val`)
            if(parent!=null && !visited.contains(parent.`val`)){
                populateResult(parent,currDist+1,K)
            }
        }
    }
    
    private fun findTarget(node: TreeNode?, target: TreeNode?){
        if(node!=null){
            if(node!=target){
                if(node.left!=null){
                    parents.put(node.left!!.`val`,node)
                    findTarget(node.left,target)
                }
                
                if(targetFound){
                    return
                }
                
                if(node.right!=null){
                    parents.put(node.right!!.`val`,node)
                    findTarget(node.right,target)
                }
            }else{
                targetFound = true
            }
        }
    }
}