//Problem Statement

/* Sort a linked list in O(n log n) time using constant space complexity. */
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* sortList(ListNode* root){
    if(!root || !root->next)
      return root;

    ListNode* slow = root, *fast =root->next;

    while(fast && fast->next){
      fast = fast->next;
      if(fast)
        fast = fast->next;
      slow = slow->next;
    }

    ListNode *mid = slow->next;
    slow->next = NULL;
    return merge(sortList(root),sortList(mid));
  }

  ListNode *merge(ListNode * l1,ListNode *l2){
    ListNode * dummy = new ListNode(-1), *it = dummy;

    while(l1 && l2){
      if(l1->val<l2->val){
        it->next = l1;
        l1 = l1->next;
      }else{
        it->next = l2;
        l2 = l2->next;
      }

      it = it->next;
    }

    if(l1){
      it->next = l1;
    }else{
      it->next = l2;
    }

    return dummy->next;
  }
};

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

ListNode * vecToLinkedList(vector<int> vec){
  ListNode *dummy = new ListNode(-1), *it=dummy;

  for(auto val:vec){
    it->next = new ListNode(val);
    it = it->next;
  }

  return dummy->next;
}

int main(){

  Solution sol;
  vector<int> vec = {1,4,6,10,2,3,5,6,8,13};
  ListNode * mList = vecToLinkedList(vec);
  printListNode(mList);
  ListNode * sorted = sol.sortList(mList);
  printListNode(sorted);
  return 0;
}
