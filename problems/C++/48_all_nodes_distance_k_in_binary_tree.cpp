// Problem Statement
// We are given a binary tree (with root node root), a target node, and an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the
// target node.  The answer can be returned in any order.

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<TreeNode *,vector<TreeNode*>> graph;

        createGraph(root,graph);

        return bfs(graph,target,K);
    }

    void createGraph(TreeNode *node,map<TreeNode *,vector<TreeNode*>> &graph){
        if(!node)
            return;

        if(node->left){
            graph[node->left].push_back(node);
            graph[node].push_back(node->left);
            createGraph(node->left,graph);
        }

        if(node->right){
            graph[node->right].push_back(node);
            graph[node].push_back(node->right);
            createGraph(node->right,graph);
        }
    }

    vector<int> bfs(map<TreeNode*,vector<TreeNode*>> &graph, TreeNode* &target, int K){
        vector<int> result;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfs_helper;

        bfs_helper.push(target);

        while(!bfs_helper.empty()){
            if(K==0){
                while(!bfs_helper.empty()){
                    TreeNode *vertex = bfs_helper.front();
                    bfs_helper.pop();
                    result.push_back(vertex->val);
                }
                break;
            }

            int tam = bfs_helper.size();
            for(int i=0;i<tam;i++){
                TreeNode* vertex = bfs_helper.front();
                bfs_helper.pop();

                if(visited.count(vertex)>0)
                    continue;

                visited.insert(vertex);

                for(auto child : graph[vertex]){
                    if(visited.count(child)==0)
                        bfs_helper.push(child);
                }
            }

            K--;
        }

        return result;
    }
};
