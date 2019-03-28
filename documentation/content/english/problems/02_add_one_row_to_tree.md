+++
title = "Add One Row to Tree"
description = "Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1."
date = 2019-02-18T19:24:15-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/add-one-row-to-tree/"
+++
<h2 class="title is-5"> Problem Statement </h2>

Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v
at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1,
create two tree nodes with value v as N's left subtree root and right subtree root.
And N's original left subtree should be the left subtree of the new left subtree root,
its original right subtree should be the right subtree of the new right subtree root.
If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v
as the new root of the whole original tree, and the original tree is the new root's left subtree.

<h2 class="title is-5"> Solution </h2>

Assuming that the node structure of the tree is:

{{< highlight cpp >}}
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
{{< /highlight >}}

The problem can be solved recursively treating the base cases:

<div class="margin_left">
  <ol>
    <li>d-1 = 0 : This condition means that we need to add a new root to the tree. Create a new node and make him root with the actual root as left children.</li>
    <li>d-1 = 1 : This node is parent of the new nodes that are going to be added. Create two new nodes for left and right and make the respective old childres of the
parent left and right childres.</li>
    <li>d-1 > 1 : This case means is necessary to go deeper in the tree. Check if the childs exists and if positive call the same function withe depth value minus 1. </li>
  </ol>
</div>

With this information the following implementation is made:

{{< highlight cpp >}}
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
{{< /highlight >}}

Time complexity **O(n)**
