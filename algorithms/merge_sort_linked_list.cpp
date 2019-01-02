// Iterative MergeSort using deque that can be used in single linked lists
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class MergeSort{
public:
  ListNode *sort(ListNode *root){

    deque<ListNode*> helper;
    ListNode *it=root,*prev;
    while(it){
        prev = it;
        it=it->next;
        prev->next = NULL;
        helper.push_back(prev);
    }

    while(helper.size()>1){
      ListNode *temp1 = helper.front();
      helper.pop_front();
      ListNode *temp2 = helper.front();
      helper.pop_front();

      ListNode *result = merge(temp1,temp2);

      helper.push_back(result);
    }

    return helper.front();
  }

  ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *dummy = new ListNode(-1),*itD = dummy;

        while(l1 && l2){
            if(l1->val<l2->val){
                itD->next = l1;
                l1 = l1->next;
            }else{
                itD->next = l2;
                l2 = l2->next;
            }
            itD= itD->next;
        }

        if(l1)
            itD->next=l1;
        else
            itD->next = l2;

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

  MergeSort merger;
  vector<int> vec = {1,4,6,10,2,3,5,6,8,13};
  ListNode * mList = vecToLinkedList(vec);
  printListNode(mList);
  ListNode * sorted = merger.sort(mList);
  printListNode(sorted);
  return 0;
}
