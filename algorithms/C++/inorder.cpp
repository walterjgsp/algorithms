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
  content.push_back(node->val);
  helperRecursive(node->right,content);
}

vector<int> preOrderRecursive(TreeNode *root){
  vector<int> to_return;
  helperRecursive(root,to_return);
  return to_return;
}

// Iterative implementation
vector<int> inOrder(TreeNode *root){
  stack<TreeNode*> traverse;
  vector<int> to_return;

  if(!root)
      return to_return;

  traverse.push(root);

  while(traverse.top()->left)
      traverse.push(traverse.top()->left);

  while(!traverse.empty()){
      TreeNode *aux = traverse.top();
      traverse.pop();
      to_return.push_back(aux->val);
      if(aux->right){
          aux=aux->right;
          while(aux){
              traverse.push(aux);
              aux=aux->left;
          }
      }
  }

  return to_return;
}
