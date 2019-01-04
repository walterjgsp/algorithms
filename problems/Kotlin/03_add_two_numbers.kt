// Problem Statement

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
class ListNode(var `val`: Int = 0) {
     var next: ListNode? = null
}

class Solution constructor() {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var irl1: ListNode? = l1;
        var irl2: ListNode? = l2;
        var dummy: ListNode? = ListNode(-1);
        var it: ListNode? = dummy;
        var carry: Int = 0;

        while(irl1!=null || irl2!=null){
            var v1:Int = 0;
            var v2:Int = 0;

            if(irl1!=null){
                v1 = irl1.`val`;
                irl1 = irl1?.next;
            }

            if(irl2!=null){
                v2 = irl2.`val`;
                irl2 = irl2?.next;
            }

            var sum: Int = v1+v2+carry;
            if(sum>9){
                carry = 1;
                sum = sum % 10;
            }else
                carry = 0;

            it?.next = ListNode(sum);
            it = it?.next;
        }

        if(carry>0)
            it?.next = ListNode(carry);

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
  val vec1 : IntArray = intArrayOf(2,4,3);
  val vec2 : IntArray = intArrayOf(5,6,4);
  val list1 : ListNode? = vecToLinkedList(vec1);
  val list2 : ListNode? = vecToLinkedList(vec2);
  printListNode(list1);
  printListNode(list2);
  var solution : Solution = Solution();
  printListNode(solution.addTwoNumbers(list1,list2));
}
