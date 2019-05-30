#include <bits/stdc++.h>

using namespace std;

enum TraverseWay {INORDER,PREORDER,POSTORDER,LEVELORDER};

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int x){
        data = x, left = nullptr, right = nullptr;
    }

    void printTreeNode(){
        cout<<"("<<data<<",";
        if(left) cout<<left->data; 
        else cout<<"-";
        cout<<",";

        if(right) cout<<right->data; 
        else cout<<"-";
        cout<<")";
    }
};

TreeNode* vecToTree(const vector<int> &vec, int i, int j){
    if(i>j){
        return nullptr;
    }

    TreeNode *it = nullptr;
    if(i==j){
        it = new TreeNode(vec[i]);
    }else{
        int mid = i + (j-i)/2;
        it = new TreeNode(vec[mid]);
        it->left = vecToTree(vec,i,mid-1);
        it->right = vecToTree(vec,mid+1,j);
    }
    
    return it;
}

void printTreeInorder(TreeNode *root){
    if(!root)
        return;

    printTreeInorder(root->left);
    cout<<root->data<<" ";
    printTreeInorder(root->right);
}

void printTreePostorder(TreeNode *root){
    if(!root)
        return;

    printTreePostorder(root->left);
    printTreePostorder(root->right);
    cout<<root->data<<" ";
}

void printTreePreorder(TreeNode *root){
    if(!root)
        return;

    cout<<root->data<<" ";
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

void printTreeLevelorder(TreeNode *root){
    if(!root)
        return;
  
    queue<TreeNode *> q; 
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        TreeNode *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 
        if (node->left != NULL) 
            q.push(node->left); 
        if (node->right != NULL) 
            q.push(node->right); 
    } 
}

class BTIterator{
private:
    TraverseWay traverse;
    deque<TreeNode*> cache;

    void initTraverse(TraverseWay traverse, TreeNode* root){
        switch (traverse){
            case LEVELORDER:
                cache.push_back(root);
            break;
            case INORDER:{
                TreeNode *it = root;
                while(it){
                    cache.push_back(it);
                    it = it->left;
                }
            }
            break;
            case PREORDER:
                cache.push_back(root);
            break;
            case POSTORDER:{
                TreeNode *it = root;
                while(it){
                    if(it->right){
                        cache.push_back(it->right);
                    }
                    cache.push_back(it);
                    it = it->left;
                }
            }
            break;
        }
    }

    TreeNode* nextLevelorder(){
        TreeNode* curr = cache.front();
        cache.pop_front();
        if(curr->left) cache.push_back(curr->left);
        if(curr->right)cache.push_back(curr->right);
        return curr;
    }

    TreeNode* nextInorder(){
        TreeNode* curr= cache.back(),*it = curr;
        cache.pop_back();
        if(it->right){
            it = it->right;
            while(it){
                cache.push_back(it);
                it = it->left;
            }
        }

        return curr;
    }

    TreeNode* nextPreorder(){
        TreeNode* curr= cache.back();
        cache.pop_back();
        if(curr->right) cache.push_back(curr->right);
        if(curr->left)cache.push_back(curr->left);
        return curr;
    }

    TreeNode* nextPostorder(){
        TreeNode *curr = cache.back();
        cache.pop_back();
        while(!cache.empty() && curr->right && curr->right == cache.back()){
            TreeNode *it = cache.back();
            cache.pop_back();
            cache.push_back(curr);
            while(it){
                if(it->right){
                    cache.push_back(it->right);
                }
                cache.push_back(it);
                it = it->left;
            }
            curr=cache.back();
            cache.pop_back();
        }
        return curr;
    }

public:
    BTIterator(TraverseWay t, TreeNode *root){
        cache.clear();
        traverse = t;
        initTraverse(t,root);
    }

    bool hasNext(){
        return !cache.empty();
    }

    TreeNode* next(){
        switch (traverse){
            case LEVELORDER:
                return nextLevelorder();
            break;
            case INORDER:
                return nextInorder();
            break;
            case PREORDER:
                return nextPreorder();
            break;
            case POSTORDER:
                return nextPostorder();
            break;
        }
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    TreeNode *tree = vecToTree(arr,0,arr.size()-1);
    BTIterator *iter = new BTIterator(INORDER,tree);

    cout<<"Inorder: "<<endl;
    printTreeInorder(tree);
    cout<<endl;
    while(iter->hasNext()){
        cout<<iter->next()->data<<" ";
    }
    cout<<endl;

    cout<<"Levelorder: "<<endl;
    printTreeLevelorder(tree);
    cout<<endl;
    iter = new BTIterator(LEVELORDER,tree);
    while(iter->hasNext()){
        cout<<iter->next()->data<<" ";
    }
    cout<<endl;

    cout<<"Preorder: "<<endl;
    printTreePreorder(tree);
    cout<<endl;
    iter = new BTIterator(PREORDER,tree);
    while(iter->hasNext()){
        cout<<iter->next()->data<<" ";
    }
    cout<<endl;

    cout<<"Posrtorder: "<<endl;
    printTreePostorder(tree);
    cout<<endl;
     iter = new BTIterator(POSTORDER,tree);
    while(iter->hasNext()){
        cout<<iter->next()->data<<" ";
    }
    cout<<endl;

    return 0;
}