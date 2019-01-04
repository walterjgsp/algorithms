// Problem Statement

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *dummy = new ListNode(-1), *it = dummy;
      int carry=0;

      while (l1 || l2) {
        int val1=0,val2=0;

        if(l1){
          val1 = l1->val;
          l1 = l1->next;
        }
        if(l2){
          val2 = l2->val;
          l2 = l2->next;
        }

        int sum = val1+val2+carry;
        if(sum>9){
          carry=1;
          sum%=10;
        }else{
          carry=0;
        }

        it->next = new ListNode(sum);
        it = it->next;
      }

      if(carry>0){
        it->next = new ListNode(1);
      }

      return dummy->next;
    }
};

ListNode *intToLinkedList(int val){
  ListNode * dummy = new ListNode(0),*it = dummy;
  if(val == 0){
    return dummy;
  }

  while (val>0) {
    int last = val%10;
    it->next = new ListNode(last);
    it = it->next;
    val/=10;
  }

  return dummy->next;
}

void printListNode(ListNode *root){
  if(!root)
    return;
  ListNode *it = root;
  while (it) {
    cout<<it->val<<"->";
    it=it->next;
  }
  cout<<"NULL"<<endl;
}

int main(){
  Solution sol;
  ListNode *l1 = intToLinkedList(100),*l2 = intToLinkedList(14);
  printListNode(sol.addTwoNumbers(l1,l2));
  return 0;
}
