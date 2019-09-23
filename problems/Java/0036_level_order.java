// Problem Statement
// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        Queue<TreeNode> bfs = new LinkedList();
        
        if(root==null){
            return result;
        }
        
        bfs.add(root);
        
        while(!bfs.isEmpty()){
            int tam = bfs.size();
            
            result.add(new ArrayList<Integer>());
            
            for(int i=0;i<tam;i++){
                TreeNode curr = bfs.remove();
                result.get(result.size()-1).add(curr.val);
                if(curr.left!=null){
                    bfs.add(curr.left);
                }
                
                if(curr.right!=null){
                    bfs.add(curr.right);
                }
            }
        }
        
        return result;
    }
}