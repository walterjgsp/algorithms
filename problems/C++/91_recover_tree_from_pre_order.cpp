// Problem Statement
// We run a preorder depth first search on the root of a binary tree.
//
// At each node in this traversal, we output D dashes (where D is the depth of this node),
// then we output the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.
// The depth of the root node is 0.)
//
// If a node has only one child, that child is guaranteed to be the left child.
//
// Given the output S of this traversal, recover the tree and return its root.
// Input: "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]
#include <bits/stdc++.h>

using namespce std;

class Solution {
public:
    int atoi(string s, int index,int n){
        if(index>=s.size())
            return n;
        return atoi(s,index+1,(n<<1)+(n<<3)+s[index]-'0');
    }

    TreeNode* recoverFromPreorder(string S) {
        int index = 0,depth=0;
        stack<TreeNode*> trav;
        string value="";

        while(index<S.size()){
            if(isdigit(S[index])){
                while(isdigit(S[index])){
                    value.push_back(S[index]);
                    index++;
                }

                TreeNode *node = new TreeNode(atoi(value,0,0));
                value = "";

                while(!trav.empty() && trav.size()>depth){
                    trav.pop();
                }

                depth=0;

                if(!trav.empty()){
                    if(!trav.top()->left) trav.top()->left = node;
                    else if(!trav.top()->right) trav.top()->right = node;
                }

                trav.push(node);

            }else{

                depth++;
                index++;
            }
        }

        while(trav.size()>1) trav.pop();

        return trav.top();
    }
};
