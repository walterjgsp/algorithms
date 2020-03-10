package org.algorithm.algorithms

class BinarySearch {
    fun binarySearch(arr:IntArray,target:Int) : Int{
        var start: Int = 0;
        var end:Int = arr.size-1;

        while(start<=end){
            val mid:Int = start+(end-start)/2;

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