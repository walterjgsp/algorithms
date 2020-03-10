package org.algorithm.problems

class `0001_two_sum` {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val visited = HashMap<Int,Int>();
        val to_return : IntArray = IntArray(2)
        for((index, num) in nums.withIndex()){
            if(visited.containsKey(target-num)){
                to_return[0] = visited.getValue(target-num)
                to_return[1] = index
                return to_return
            }
            visited[num] = index;
        }
        return to_return;
    }
}