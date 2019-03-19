//Problem Statement

/* Sort a linked list in O(n log n) time using constant space complexity. */

class ListNode(var `val`: Int = 0) {
     var next: ListNode? = null
}

class Solution {
    fun sortList(head: ListNode?): ListNode? {

        if(head == null )
            return head;

        var helper:MutableList<ListNode?> = mutableListOf<ListNode?>();
        var iterator: ListNode? = head;

        while(iterator!=null){
            var prev: ListNode?;
            prev = iterator;
            iterator = iterator.next;
            prev.next = null;
            helper.add(prev);
        }

        while(helper.size>1){
            var l1: ListNode? = helper[0];
            helper.removeAt(0);
            var l2: ListNode? = helper[0];
            helper.removeAt(0);
            var result: ListNode? = merge(l1,l2);
            helper.add(result);
        }

        return helper[0];
    }

    fun merge(l1: ListNode?, l2: ListNode?): ListNode?{
        var dummy: ListNode? = ListNode(-1);
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

        if(itl1==null)
            iterator?.next = itl2;
        else
            iterator?.next = itl1;

        return dummy?.next;
    }
}

fun vecToLinkedList(vec: IntArray) : ListNode?{

  var dummy : ListNode? = ListNode(-1);
  var iterator : ListNode? = dummy;
  for(index in vec.indices){
    iterator?.next = ListNode(vec[index]);
    iterator = iterator?.next;
  }

  return dummy?.next;
}

fun printListNode(list : ListNode?){
  var iterator: ListNode? = list;
  while(iterator!=null){
    print("${iterator.`val`} ");
    iterator = iterator.next;
  }
  println();
}

fun main(args:Array<String>){
  val vec : IntArray  = intArrayOf(8,10,1,3,2,15);
  val list : ListNode? = vecToLinkedList(vec);
  printListNode(list);
  var merger : Solution = Solution();
  printListNode(merger.sortList(list));
}
