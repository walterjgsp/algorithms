//Problem Statement
// A linked list is given such that each node contains an additional random pointer
// which could point to any node in the list or null.
//
// Return a deep copy of the list.
#include <bits/stdc++/h>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> copyList;
        
        Node *it = head;

        while(it){
            copyList[it]=new Node(it->val);
            it = it->next;
        }

        Node *newHead = copyList[head], *itN = newHead;
        it = head;
        while(it){
            itN->next = copyList[it->next];
            itN->random = copyList[it->random];
            it = it->next,itN = itN->next;
        }

        return newHead;
    }
};
