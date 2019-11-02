// Iterative MergeSort using deque that can be used in single linked lists
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
//
class ListNode(var num: Int = 0) {
  var next: ListNode? = null;
}

class MergeSort constructor(){

  fun mergeSort(list : ListNode?) : ListNode?{
    var helper: MutableList<ListNode?> = mutableListOf<ListNode?>();
    var iterator: ListNode? = list;

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

  fun merge(l1 : ListNode?, l2 :ListNode?) :ListNode?{

    var dummy : ListNode? = ListNode(-1);
    var iterator: ListNode? = dummy;
    var itl1: ListNode? = l1;
    var itl2: ListNode? = l2;
    while(itl1!=null && itl2!=null){
      if(itl1.num<itl2.num){
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
    print("${iterator.num} ");
    iterator = iterator.next;
  }
  println();
}

fun main(args:Array<String>){
  val vec : IntArray  = intArrayOf(8,10,1,3,2,15);
  val list : ListNode? = vecToLinkedList(vec);
  printListNode(list);
  var merger : MergeSort = MergeSort();
  printListNode(merger.mergeSort(list));
}
