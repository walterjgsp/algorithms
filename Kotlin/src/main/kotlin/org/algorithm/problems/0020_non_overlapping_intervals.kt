// Problem Statement
// Given a collection of intervals, find the minimum number of intervals you need
// to remove to make the rest of the intervals non-overlapping.
//
// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
//
// Input: [ [1,2], [2,3], [3,4], [1,3] ]
// Output: 1
package org.algorithm.problems

class `0020_non_overlapping_intervals` {
    fun eraseOverlapIntervals(intervals: Array<IntArray>): Int {
        if(intervals.isEmpty()) 
            return 0
        
        intervals.sortWith(Comparator{ i1: IntArray, i2: IntArray ->
            if(i1[1] == i2[1]) i1[0]-i2[0]
            else i1[1] - i2[1]
        })
        
        var currInterval = intervals[0]
        var result = 0
        
        for(i in 1 until intervals.size){
            if(currInterval[1]>intervals[i][0]){
                result+=1
            }else{
                currInterval = intervals[i]
            }
        }
        return result
    }
}