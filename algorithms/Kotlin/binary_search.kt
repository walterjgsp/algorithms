//Simple binary search in a sorted list.
//Time Complexity O(logn)
//Space Complexity: O(1)
//n is the size of the array

class BinarySearch constructor(){
  fun binarySearch(arr:IntArray,target:Int) : Int{
    var start: Int = 0;
    var end:Int = arr.size-1;

    while(start<=end){
      var mid:Int = start+(end-start)/2;

      if(arr[mid]==target)
        return mid;
      else if(arr[mid]<target)
        start = mid+1;
      else
        end = mid-1;
    }

    return -1;
  }
}

fun main(args:Array<String>){
  var arr:IntArray = intArrayOf(1,2,3,5,7,8,10);
  var binary_search:BinarySearch = BinarySearch();
  println(binary_search.binarySearch(arr,5));
  /* Or you can use the library implemented Binary Search */
  println(arr.binarySearch(5));
}
