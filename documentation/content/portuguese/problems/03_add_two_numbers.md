+++
title = "Add Two Numbers"
description = "Add the two numbers and return it as a linked list."
date = 2019-02-18T21:24:09-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/add-two-numbers/"
+++
<h2 class="title is-5"> Problem Statement </h2>

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

<h2 class="title is-5"> Solution </h2>

Assuming a list node like this:

{{< highlight cpp >}}
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
{{< /highlight >}}

Since the digits are already stored in reverse order with the less significant value first
and the return must be the same way, is only necessary to execute the add operation in each
value taking care to not lose any pointer and avoid access to null pointer nodes.

The solution become simple and the implementation straightforward.

{{< highlight cpp >}}
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
    carry=sum/10;
    sum%=10;

    it->next = new ListNode(sum);
    it = it->next;
  }

  if(carry>0){
    it->next = new ListNode(1);
  }

  return dummy->next;
}
{{< /highlight >}}

Time complexity **O(max(n,m))** where n is the size of list1 and m the size of list2
