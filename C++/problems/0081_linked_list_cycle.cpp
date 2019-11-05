// Problem Statement
// Given a linked list, determine if it has a cycle in it.
//
// To represent a cycle in the given linked list, we use an integer pos which
// represents the position (0-indexed) in the linked list where tail connects to.
// If pos is -1, then there is no cycle in the linked list.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;

        ListNode *fast = head->next, *slow = head;
        while(fast!=NULL && fast!=slow){
            fast= fast->next;
            if(fast)
                fast = fast->next;
            slow = slow->next;
        }

        return fast==slow;
    }
};
