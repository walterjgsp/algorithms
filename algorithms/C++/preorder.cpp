#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left,*right;
  TreeNode(x){
    val = x;
    left=NULL;
    right=NULL;
  }
};


// Recursive implementation
void helperRecursive(TreeNode *node,vector<int> &content){
  if(!node)
    return;

  content.push_back(node->val);
  helperRecursive(node->left,content);
  helperRecursive(node->right,content);
}

vector<int> preOrderRecursive(TreeNode *root){
  vector<int> to_return;
  helperRecursive(root,to_return);
  return to_return;
}

// Iterative implementation
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> traverse;
    vector<int> to_return;

    if(!root)
        return to_return;

    traverse.push(root);

    while(!traverse.empty()){
        TreeNode *node = traverse.top();
        traverse.pop();

        to_return.push_back(node->val);
        if(node->right)
            traverse.push(node->right);
        if(node->left)
            traverse.push(node->left);
    }

    return to_return;
}
