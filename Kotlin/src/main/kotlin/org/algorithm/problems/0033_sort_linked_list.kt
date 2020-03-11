//Problem Statement

/* Sort a linked list in O(n log n) time using constant space complexity. */

package org.algorithm.problems

import org.algorithm.shared.ListNode

class `0033_sort_linked_list` {
    fun sortList(head: ListNode?): ListNode? {

        if (head == null)
            return head;

        var helper: MutableList<ListNode?> = mutableListOf<ListNode?>();
        var iterator: ListNode? = head;

        while (iterator != null) {
            var prev: ListNode?;
            prev = iterator;
            iterator = iterator.next;
            prev.next = null;
            helper.add(prev);
        }

        while (helper.size > 1) {
            var l1: ListNode? = helper[0];
            helper.removeAt(0);
            var l2: ListNode? = helper[0];
            helper.removeAt(0);
            var result: ListNode? = merge(l1, l2);
            helper.add(result);
        }

        return helper[0];
    }

    fun merge(l1: ListNode?, l2: ListNode?): ListNode? {
        val dummy: ListNode? = ListNode(-1);
        var iterator: ListNode? = dummy;
        var itl1: ListNode? = l1;
        var itl2: ListNode? = l2;

        while (itl1 != null && itl2 != null) {
            if (itl1.`val` < itl2.`val`) {
                iterator?.next = itl1;
                itl1 = itl1.next;
            } else {
                iterator?.next = itl2;
                itl2 = itl2.next;
            }

            iterator = iterator?.next;
        }

        if (itl1 == null)
            iterator?.next = itl2;
        else
            iterator?.next = itl1;

        return dummy?.next;
    }
}