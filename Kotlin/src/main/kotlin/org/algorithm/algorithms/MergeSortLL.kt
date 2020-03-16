// Iterative MergeSort using deque that can be used in single linked lists
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
//
package org.algorithm.algorithms

import org.algorithm.shared.ListNode

class MergeSortLL{

  fun mergeSort(list : ListNode?) : ListNode?{
    val helper: MutableList<ListNode?> = mutableListOf<ListNode?>();
    var iterator: ListNode? = list;

    while(iterator!=null){
      var prev: ListNode?;
      prev = iterator;
      iterator = iterator.next;
      prev.next = null;
      helper.add(prev);
    }

    while(helper.size>1){
      val l1: ListNode? = helper[0];
      helper.removeAt(0);
      val l2: ListNode? = helper[0];
      helper.removeAt(0);
      val result: ListNode? = merge(l1,l2);
      helper.add(result);
    }

    return helper[0];
  }

  fun merge(l1 : ListNode?, l2 :ListNode?) :ListNode?{

    val dummy : ListNode? = ListNode(-1);
    var iterator: ListNode? = dummy;
    var itl1: ListNode? = l1;
    var itl2: ListNode? = l2;
    while(itl1!=null && itl2!=null){
      if(itl1.`val`<itl2.`val`){
        iterator?.next = itl1;
        itl1 = itl1.next;
      }else{
        iterator?.next = itl2;
        itl2 = itl2.next;
      }
      iterator = iterator?.next;
    }

    if(itl1==null){
      iterator?.next = itl2;
    }else{
      iterator?.next = itl1;
    }

    return dummy?.next;
  }
}
