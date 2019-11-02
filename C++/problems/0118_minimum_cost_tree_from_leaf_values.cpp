// Problem Statement
// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  
// (Recall that a node is a leaf if and only if it has 0 children.)
// The value of each non-leaf node is equal to the product of the largest leaf value in its left 
// and right subtree respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of 
// each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.
#include <bits/stdc++.h>

using namespace std;

void printVec(const vector<int> &vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

class Solution {
private:
    vector<int> max_left, max_right;
    map<pair<int,int>,pair<int,int>> memo;

    pair<int,int> dp(const vector<int> &arr, int i, int j){
        pair<int,int> curr = make_pair(i,j);
        if(memo.find(curr)!=memo.end()){
            return memo[curr];
        }

        if(i==j){
            return memo[curr] = {0,arr[i]};
        }

        pair<int,int> result = {INT_MAX,INT_MIN};
        for(int k=i;k<j;k++){
            auto left = dp(arr,i,k);
            auto right = dp(arr,k+1,j);
            pair<int,int> curr_result = {left.second*right.second+left.first+right.first,max(left.second,right.second)};
            result = min(result,curr_result);
        }

        return memo[curr] =result;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        return dp(arr,0,arr.size()-1).first;
    }
};

int main(){
    vector<int> leafs = {6,2,4,5};
    Solution sol;
    cout<<sol.mctFromLeafValues(leafs)<<endl;
    return 0;
}

