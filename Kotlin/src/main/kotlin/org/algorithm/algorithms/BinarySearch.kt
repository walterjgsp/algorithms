package org.algorithm.algorithms

class BinarySearch {
    fun binarySearch(arr: IntArray, target: Int): Int {
        var start = 0
        var end: Int = arr.size - 1

        while (start <= end) {
            val mid: Int = start + (end - start) / 2

            when {
                arr[mid] == target -> return mid
                arr[mid] < target -> start = mid + 1
                else -> end = mid - 1
            }
        }

        return -1
    }
}