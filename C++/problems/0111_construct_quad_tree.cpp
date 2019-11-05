// Problem Statment
// We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be 
// true or false. The root node represents the whole grid. For each node, it will be subdivided 
// into four children nodes until the values in the region it represents are all the same.

// Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if 
// the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

// Your task is to use a quad tree to represent a given grid.
#include<bits/stdc++.h>

using namespace std;

class QuadNode {
public:
    bool val;
    bool isLeaf;
    QuadNode* topLeft;
    QuadNode* topRight;
    QuadNode* bottomLeft;
    QuadNode* bottomRight;

    QuadNode() {}

    QuadNode(bool _val, bool _isLeaf, QuadNode* _topLeft, QuadNode* _topRight, QuadNode* _bottomLeft, QuadNode* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    QuadNode* construct(vector<vector<int>>& grid) {
        return helper({0,0},{grid.size()-1,grid.size()-1},grid);
    }
    
    QuadNode* helper(pair<int,int> topLeft, pair<int,int> bottomRight, const vector<vector<int>>& grid){
        if(bottomRight==topLeft){
            int i = topLeft.first, j = topLeft.second;
            return new QuadNode(grid[i][j],true,nullptr,nullptr,nullptr,nullptr);
        }
        
        int midX = (topLeft.first+bottomRight.first)/2;
        int midY = (topLeft.second+bottomRight.second)/2;
        
        QuadNode *topLeftNode = helper(topLeft,{midX,midY},grid);
        QuadNode *topRightNode = helper({topLeft.first,midY+1},{midX,bottomRight.second},grid);
        QuadNode *bottomLeftNode = helper({midX+1,topLeft.second},{bottomRight.first,midY},grid);
        QuadNode *bottomRightNode = helper({midX+1,midY+1},bottomRight,grid);
        
        QuadNode *newRoot;
        
        if((topLeftNode->isLeaf && topRightNode->isLeaf && bottomLeftNode->isLeaf && bottomRightNode->isLeaf)
          && (topLeftNode->val == topRightNode->val && bottomLeftNode->val == bottomRightNode->val 
          && topLeftNode->val == bottomLeftNode->val)){
            newRoot = new QuadNode(topLeftNode->val,true,nullptr,nullptr,nullptr,nullptr);
        }else{
            newRoot = new QuadNode(true,false,topLeftNode,topRightNode,bottomLeftNode,bottomRightNode);
        }
        
        return newRoot;
    }
};