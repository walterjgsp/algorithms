package org.algorithm.structures

class SegTree(val array: IntArray) {
    private var treeArray: MutableList<Int>
    private var arrSize: Int

    init {
        treeArray = MutableList<Int>(4 * array.size) { 0 }
        initSegTree(array, 0, 0, array.size - 1)
        arrSize = array.size
        println(treeArray)
    }

    private fun initSegTree(array: IntArray, treeIndex: Int, start: Int, end: Int): Int {
        if (start == end) {
            treeArray[treeIndex] = array[start]
        } else {
            val mid: Int = start + (end - start) / 2
            treeArray[treeIndex] = initSegTree(array, 2 * treeIndex + 1, start, mid) + initSegTree(array, 2 * treeIndex + 2, mid + 1, end)
        }

        return treeArray[treeIndex]
    }

    private fun queryHelper(treeIndex: Int, currStart: Int, currEnd: Int, start: Int, end: Int): Int {
        return if (currStart > end || currEnd < start) {
            return 0
        } else if (currStart == currEnd) {
            treeArray[treeIndex]
        } else if (currStart >= start && currEnd <= end) {
            treeArray[treeIndex]
        } else {
            val mid = currStart + (currEnd - currStart) / 2
            queryHelper(2 * treeIndex + 1, currStart, mid, start, end) + queryHelper(2 * treeIndex + 2, mid + 1, currEnd, start, end)
        }
    }

    private fun updateHelper(treeIndex: Int, currStart: Int, currEnd: Int, start: Int, end: Int, value: Int): Int {
        if (currStart > end || currEnd < start) {
            return treeArray[treeIndex]
        }

        if (currStart == currEnd) {
            treeArray[treeIndex] += value
        } else {
            val mid: Int = currStart + (currEnd - currStart) / 2
            treeArray[treeIndex] = updateHelper(2 * treeIndex + 1, currStart, mid, start, end, value) +
                    updateHelper(2 * treeIndex + 2, mid + 1, currEnd, start, end, value)
        }

        return treeArray[treeIndex]
    }

    fun queryInterval(start: Int, end: Int): Int {
        return queryHelper(0, 0, arrSize - 1, start, end)
    }

    fun updateInterval(start: Int, end: Int, value: Int) {
        updateHelper(0, 0, arrSize - 1, start, end, value)
    }

    fun printSegTree() {
        println(treeArray)
    }

}

//fun main(args: Array<String>) {
//    val input = intArrayOf(1,2,3,1,3,5,6,4,1,2)
//    val segTree = SegTree(input)
//    println(segTree.queryInterval(3,7))
//    segTree.updateInterval(0,3,2)
//    segTree.printSegTree()
//}