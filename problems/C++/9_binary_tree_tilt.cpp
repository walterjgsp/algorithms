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
    int findTilt(TreeNode* root) {
        int tilt=0;
        helper(root,tilt);

        return tilt;
    }

    int helper(TreeNode *node,int &tilt){
        if(!node)
            return 0;

        int left = helper(node->left,tilt);
        int right = helper(node->right,tilt);

        tilt+=abs(left-right);

        return node->val+left+right;
    }
};

// When i implement a tree parser from string i will update this code so that i can
//show the code working.
