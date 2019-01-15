//Problem Statement
// Suppose an array sorted in ascending order is rotated at some pivot unknown to
// you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
class Solution constructor() {
    fun findMin(nums: IntArray): Int {
        var lower:Int=0;
        var higher:Int=nums.size-1;

        while(lower<higher){
            var mid:Int = lower + (higher-lower)/2;

            if(nums[mid]>nums.last()){
                lower=mid+1;
            }else{
                higher = mid;
            }
        }

        return nums[lower];
    }
}

fun main(args:Array<String>){
  var vec:IntArray = intArrayOf(4,5,6,7,0,1,2);
  val sol:Solution = Solution();

  println(sol.findMin(vec));
}
