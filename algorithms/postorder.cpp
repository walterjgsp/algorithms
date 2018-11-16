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

  helperRecursive(node->left,content);
  helperRecursive(node->right,content);
  content.push_back(node->val);
}

vector<int> postOrderRecursive(TreeNode *root){
  vector<int> to_return;
  helperRecursive(root,to_return);
  return to_return;
}


// Iterative implementation
vector<int> postOrder(TreeNode *root){
  stack<TreeNode*> traverse;
  vector<int> to_return;

  if(!root)
    return to_return;

  traverse.push(root);
  while(!traverse.empty()){
    TreeNode *aux = traverse.top();
    traverse.pop();

    to_return.push_back(aux->val);

    if(aux->left)
      traverse.push(aux->left);

    if(aux->right)
      traverse.push(aux->right);
  }

  reverse(to_return.begin(),to_return.end());

  return to_return;
}
