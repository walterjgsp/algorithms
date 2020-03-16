package org.algorithm.shared

class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null

    fun printList() {
        var iterator: ListNode? = this;
        while (iterator != null) {
            print("${iterator.`val`} ");
            iterator = iterator.next;
        }
        println();
    }

    override fun toString(): String {
        var result = ""
        var iterator: ListNode? = this;
        while (iterator != null) {
            result += iterator.`val`.toString()
            iterator = iterator.next
        }

        return result
    }
}