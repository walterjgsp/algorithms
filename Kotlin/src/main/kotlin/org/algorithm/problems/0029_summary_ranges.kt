// Problem Statement

// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
// Input:  [0,1,2,4,5,7,9,10]
// Output: ["0->2","4->5","7","9->10"]
package org.algorithm.problems

class `0029_summary_ranges` {
    data class Interval(var start:Int,var end:Int){
        override fun toString(): String{
            return if(start == end){
                start.toString()
            }else{
                "$start->$end"
            }
        }
    }
    
    fun summaryRanges(nums: IntArray): List<String> {
        val result = mutableListOf<String>()
        if(nums.isEmpty()) 
            return result
        
        var currInterval = Interval(nums[0],nums[0])
        for(i in 1 until nums.size){
            if(kotlin.math.abs(nums[i]-currInterval.end)>1){
                result.add(currInterval.toString())
                currInterval = Interval(nums[i],nums[i])
            }else{
                currInterval.end = nums[i]
            }
        }
        result.add(currInterval.toString())
        
        return result
        
    }
}