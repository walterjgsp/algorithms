#include "../frameworks/stdc++.h"

using namespace std;

class AVLTree{
private:
    struct Node{
        Node *left = nullptr, *right = nullptr;
        int value, height, quantity;
        Node(int _value){
            value = _value;
            height = 0;
            quantity = 1;
        }

        void toString(){
            cout<<"( V: "<<value<<", H: "<<height<<", L: ";
            cout<<(left ? to_string(left->value): "null")<<", R: ";
            cout<<(right ? to_string(right->value): "null")<<") ";
        }
    };

    Node* root = nullptr;

    Node* helperInsertion(Node* node, const int &value){
        if(!node){
            return new Node(value);
        }

        if(node->value == value){
            node->quantity++;
        }else if(value < node->value){
            node->left = helperInsertion(node->left,value);
        }else{
            node->right = helperInsertion(node->right,value);
        }
        node->height = calcNewHeight(node->left,node->right);

        Node* balancedNode = balanceTree(node);
        
        return balancedNode;
    }

    int calcBalance(Node* node){
        int leftHeight = getHeight(node->left), rightHeight = getHeight(node->right);
        return leftHeight - rightHeight;
    }

    int calcNewHeight(Node* leftNode, Node* rightNode){
        int leftHeight = getHeight(leftNode), rightHeight = getHeight(rightNode);
        return max(leftHeight,rightHeight)+1;
    }

    int getHeight(Node* node){
        if(node) return node->height;
        else return -1;
    }

    Node* rotateRight(Node* root){
        Node *leftNode = root->left, *rightChild = leftNode->right;
        root->left = rightChild;
        leftNode->right = root;
        root->height = calcNewHeight(root->left,root->right);
        leftNode->height = calcNewHeight(leftNode->left,leftNode->right);
        return leftNode;
    }

    Node* rotateLeft(Node* root){
        Node *rightNode = root->right, *leftChild = rightNode->left;
        root->right = leftChild;
        rightNode->left = root;
        root->height = calcNewHeight(root->left,root->right);
        rightNode->height = calcNewHeight(rightNode->left,rightNode->right);
        return rightNode;
    }

    Node* balanceTree(Node* node){
        int balance = calcBalance(node);
        if(balance > 1){ 
            if(calcBalance(node->left)>0)
                return rotateRight(node);
            else{
                node->left = rotateLeft(node->left);  
                return rotateRight(node);  
            }
        } 
        
        if(balance < -1) {
            if(calcBalance(node->right)<0){
                return rotateLeft(node);
            }
            else{
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }
        return node;
    }
    
public:
    void insert(int value){
        root = helperInsertion(root,value);
    }

    bool remove(int value){
        if(contains(value)){

            return true;
        }
        return false;
    }

    bool contains(int value){
        Node *it = root;
        while(it){
            if(it->value == value) return true;
            else if(value < it->value) it = it->left;
            else it = it->right;
        }
        return false;
    }

    void printTree(){
        queue<Node*> nodes;
        if(root){
            nodes.push(root);
        }

        while(!nodes.empty()){
            int tam = nodes.size();
            for(int i=0;i<tam;i++){
                auto currNode = nodes.front();
                nodes.pop();
                currNode->toString();
                if(currNode->left) nodes.push(currNode->left);
                if(currNode->right) nodes.push(currNode->right);
            }
            cout<<endl;
        }
    }

};

int main(){
    AVLTree tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(5);
    tree.insert(11);
    tree.insert(7);
    tree.printTree();
    cout<<"Contains: "<<tree.contains(5)<<endl;
    cout<<"Contains: "<<tree.contains(4)<<endl;

    return 0;
}