#include <bits/stdc++.h>

using namespace std;

class BinarySearchTree{
private:
    struct BNode{
        int data;
        BNode *left, *right;

        BNode(int x){
            data = x;
            left = nullptr, right = nullptr;
        }

        bool isLeaf(){
            return left == nullptr && right == nullptr;
        }
    };
    BNode *root;

    BNode* insertRecur(const int &value, BNode *node){
        if(!node){
            node = new BNode(value);
        }else if(value>node->data){
            node->right = insertRecur(value,node->right);
        }else{
            node->left = insertRecur(value,node->left);
        }

        return node;
    }

    void insertIter(const int &value){
        BNode *it = root;
        if(!it){
            it = new BNode(value);
            return;
        }
        
        while(it){
            if(it->data < value){
                if(it->right) it = it->right;
                else{
                    it->right = new BNode(value);
                    break;
                }
            }else{
                if(it->left) it = it->left;
                else{
                    it->left = new BNode(value);
                    break;
                }
            }
        }
        
    }

    void inorderPrint(BNode *node){
        if(!node)
            return;
        
        inorderPrint(node->left);
        cout<<node->data<<" ";
        inorderPrint(node->right);
    }

    BNode* findMinimumParent(BNode *node){
        if(!node)
            return nullptr;

        BNode *it = node;
        while (it->left->left){
            it = it->left;
        }
        
        return it;
    }

    BNode* remove(BNode* node,const int &value){
        if(!node)
            return node;

        if(node->data == value){
            BNode* to_delete = node, *newNode;
            if(node->left){
                newNode = node->left;
                BNode *it = newNode;
                while(it->right){
                    it = it->right;
                }

                it->right = node->right;
            }else{
                newNode = node->right;
            }
            delete to_delete;
            return newNode;
        }else if(node->data > value){
            node->left = remove(node->left,value);
        }else{
            node->right = remove(node->right,value);
        }

        return node;
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(const int &value, bool recursively = true){
        if(recursively){
            root = insertRecur(value,root);
        }else{
            insertIter(value);
        }
    }

    void remove(const int &value){
        root = remove(root,value);
    }

    void printBST(){
        inorderPrint(root);
        cout<<endl;
    }

    bool query(const int &value){
        BNode *it = root;
        if(!it)
            return false;

        while(it){
            if(it->data == value)
                return true;
            else if(it->data>value)
                it = it->left;
            else
                it = it->right;
        }

        return false;
    }

    //TODO find minimum of specific value
    int findMinimum(){
        auto it = findMinimumParent(root);
        if(it){
            return it->left->data;
        }
        return INT_MAX;
    }
};

int main(){
    BinarySearchTree binarySearchTree;
    binarySearchTree.insert(13);
    binarySearchTree.insert(7);
    binarySearchTree.insert(2,false);
    binarySearchTree.insert(11);
    binarySearchTree.insert(21,false);
    binarySearchTree.insert(9,false);
    binarySearchTree.printBST();
    cout<<binarySearchTree.query(11)<<endl;
    cout<<binarySearchTree.query(15)<<endl;
    cout<<binarySearchTree.findMinimum()<<endl;
    binarySearchTree.remove(11);
    binarySearchTree.printBST();

    return 0;
}   