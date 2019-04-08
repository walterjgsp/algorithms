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

class Solution {
public:
    vector<vector<int>> levelOrderRecursive(TreeNode* root) {
        vector<vector<int>> result;
        helperRecursive(root,result,0);
        return result;
    }

    void helperRecursive(TreeNode* node, vector<vector<int>> &result, int depth){
        if(!node)
            return;

        if(depth>=result.size()){
            vector<int> level;
            result.push_back(level);
        }

        result[depth].push_back(node->val);
        helperRecursive(node->left,result,depth+1);
        helperRecursive(node->right,result,depth+1);
    }

    vector<vector<int>> levelOrderIterative(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            vector<int> level;
            int tam = bfs.size();
            for(int i=0;i<tam;i++){
                TreeNode *actual = bfs.front();
                bfs.pop();
                level.push_back(actual->val);
                if(actual->left)
                    bfs.push(actual->left);
                if(actual->right)
                    bfs.push(actual->right);
            }
            result.push_back(level);
        }

        return result;
    }
};
