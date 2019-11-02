// Problem Statement
// Lauren has a chart of distinct projected prices for a house over the next several years. 
// She must buy the house in one year and sell it in another, and she must do so at a loss. 
// She wants to minimize her financial loss.

// She can purchase the home in any year, but she must resell the house at a loss in one of the following years.
// Find and print the minimum amount of money Lauren must lose if she buys the house and resells it within the next  years.

// Note: It's guaranteed that a valid answer exists.
#include <bits/stdc++.h>

using namespace std;

class BST{
private:
    struct BNode{
        int value;
        BNode *left, *right;
        BNode(int x){
            value = x;
            left = nullptr, right = nullptr;
        }
    };

    BNode* root = nullptr;

    BNode* insertHelper(const int &val, BNode *node){
        if(!node){
            node = new BNode(val);
        }
        else if(val<node->value){
            node->left = insertHelper(val,node->left);
        }else{
            node->right = insertHelper(val, node->right);
        }

        return node;
    }

public: 
    void insert(const int &x){
        root = insertHelper(x,root);
    }

    int minBiggest(const int &x) {
        int minBig = -1;
        BNode *it = root;
        while (it) {
            if (x > it->value) {
                it = it->right;
            } else {
                minBig = it->value;
                it = it->left;
            }
        }

        return minBig;
    }
};

class Solution{
public:
    int minimumLoss(vector<int> price) {
        BST bst;
         int result = INT_MAX;
        for(auto val : price){
            int minBig = bst.minBiggest(val);
            if(minBig!=-1){
                result = min(result, minBig-val);
            }
            bst.insert(val);
        }

        return result;
    }
};

int main(){
    vector<int> prices = {20,7,8,2,5};
    Solution sol;
    cout<<sol.minimumLoss(prices)<<endl;
    return 0;
}