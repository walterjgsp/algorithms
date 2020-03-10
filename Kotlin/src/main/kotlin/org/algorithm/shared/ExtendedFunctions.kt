package org.algorithm.shared

fun IntArray.vecToLinkedList() : ListNode?{

    var dummy : ListNode? = ListNode(-1);
    var iterator : ListNode? = dummy;
    for(index in this.indices){
        iterator?.next = ListNode(this[index]);
        iterator = iterator?.next;
    }

    return dummy?.next;
}