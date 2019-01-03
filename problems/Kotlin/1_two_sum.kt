class Solution constructor() {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val visited = HashMap<Int,Int>();
        val to_return : IntArray = IntArray(2)
        var index : Int = 0;
        for(num in nums){
            if(visited.containsKey(target-num)){
                to_return[0] = visited.getValue(target-num);
                to_return[1] = index;
                return to_return;
            }
            visited.put(num,index);
            index++;
        }
        return to_return;
    }
}

fun main(args: Array<String> ){
  val nums: IntArray = intArrayOf(2, 7, 11, 15);
  val target: Int = 9;
  val sol:Solution = Solution();
  println(sol.twoSum(nums,target).joinToString(", "));
}
