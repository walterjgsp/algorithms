//Problem Statement
// Return all non-negative integers of length N such that the
// absolute difference between every two consecutive digits is K.
//
// Note that every number in the answer must not have leading zeros except for
// the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.
//
// You may return the answer in any order.
package org.algorithm.problems

class `0021_numbers_with_same_consecutive_differences` {

    private val result = mutableSetOf<Int>()

    private fun consecHelper(currValue: Int, lastValue: Int, size: Int, K: Int) {
        if (size == 0) {
            result.add(currValue)
        } else {
            if (lastValue - K >= 0) {
                val nextValue = lastValue - K
                consecHelper((currValue * 10) + nextValue, nextValue, size - 1, K)
            }

            if (lastValue + K < 10) {
                val nextValue = lastValue + K
                consecHelper((currValue * 10) + nextValue, nextValue, size - 1, K)
            }
        }
    }

    fun numsSameConsecDiff(N: Int, K: Int): IntArray {
        if (N == 1) {
            result.add(0)
        }
        for (i in 1..9) {
            consecHelper(i, i, N - 1, K)
        }
        return result.toIntArray()
    }
}