// Problem Statement

// Given the root of a binary tree, then value v and depth d, you need to add a
// row of nodes with value v at the given depth d. The root node is at depth 1.
//
// The adding rule is: given a positive integer depth d, for each NOT null tree
// nodes N in depth d-1, create two tree nodes with value v as N's left subtree
// root and right subtree root. And N's original left subtree should be the left
// subtree of the new left subtree root, its original right subtree should be the
// right subtree of the new right subtree root. If depth d is 1 that means there
// is no depth d-1 at all, then create a tree node with value v as the new root
// of the whole original tree, and the original tree is the new root's left subtree.
//
// Example:
//        4               4
//      /   \           /   \
//     2     6   =>   1      1
//    / \   /        /        \
//   3   1 5        2          6
//                /  \        /
// v = 1        3     1      5
// d = 2
package org.algorithm.problems

import org.algorithm.shared.TreeNode

class `0002_add_one_row_to_tree` {
    fun addOneRow(root: TreeNode?, v: Int, d: Int): TreeNode? {
        if(root==null)
            return root;

        var to_return: TreeNode? = root;

        if(d==1){
            val newRoot: TreeNode? = TreeNode(v);
            newRoot?.left = to_return;
            to_return = newRoot;
        }
        else if(d==2){
            val newNodeL:TreeNode? = TreeNode(v);
            newNodeL?.left = to_return?.left;
            to_return?.left = newNodeL;

            val newNodeR:TreeNode? = TreeNode(v);
            newNodeR?.right = to_return?.right;
            to_return?.right = newNodeR;
        }else{
            to_return?.left = addOneRow(to_return?.left,v,d-1);
            to_return?.right = addOneRow(to_return?.right,v,d-1);
        }

        return to_return;
    }
}
