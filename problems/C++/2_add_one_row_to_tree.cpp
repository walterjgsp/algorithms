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

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x){
    val = x;
    left = NULL;
    right = NULL;
  }
}

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {

        if(d-1==0){
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }


        if(d-1==1){
            TreeNode *newleft = new TreeNode(v), *newright = new TreeNode(v);
            newleft->left = root->left;
            newright->right = root->right;
            root->left = newleft;
            root->right = newright;
        }else{
            if(root->left) addOneRow(root->left,v,d-1);
            if(root->right)addOneRow(root->right,v,d-1);
        }
        return root;
    }
};

// When i implement a tree parser from string i will update this code so that i can
//show the code working.
