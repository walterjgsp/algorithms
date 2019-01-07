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

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        stack<TreeNode *> dfs;
        int index = 0;
        vector<int> flipped, wrong = {-1};

        dfs.push(root);

        while(!dfs.empty()){
            TreeNode *node = dfs.top();
            dfs.pop();

            if(node->val!=voyage[index])
                return wrong;

            if(node->left && node->left->val == voyage[index+1]){
                if(node->right) dfs.push(node->right);
                dfs.push(node->left);
            }else if(node->left){
                flipped.push_back(node->val);
                dfs.push(node->left);
                if(node->right)
                    dfs.push(node->right);
                else
                    return wrong;
            }else{
                if(node->right)
                    dfs.push(node->right);
            }

            index++;
        }

        return flipped;
    }
};
