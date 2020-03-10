// Problem Statement

// Given a binary tree, return the tilt of the whole tree.
//
// The tilt of a tree node is defined as the absolute difference between the sum
// of all left subtree node values and the sum of all right subtree node values.
// Null node has tilt 0.
//
// The tilt of the whole tree is defined as the sum of all nodes' tilt.
//
// Input:
//          1
//        /   \
//       2     3
// Output: 1
/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    private var result:Int = 0;
    fun findTilt(root: TreeNode?): Int {
        result = 0;

        helperTilt(root);

        return result;
    }

    fun helperTilt(node: TreeNode?): Int{

        if(node==null)
            return 0;

        var sumLeft:Int = helperTilt(node?.left);
        val sumRight:Int = helperTilt(node?.right);

        result += kotlin.math.abs(sumRight - sumLeft);

        return node.`val`+sumRight+sumLeft;
    }
}
