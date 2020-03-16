// Problem Statement
// We are given hours, a list of the number of hours worked per day for a given employee.

// A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

// A well-performing interval is an interval of days for which the number of tiring days is strictly larger than
// the number of non-tiring days.

// Return the length of the longest well-performing interval.
package org.algorithm.problems

class `0119_longest_well_performing_interval` {
    fun longestWPI(hours: IntArray): Int {
        var sum: Int = 0;
        var result: Int = 0;
        val memo = hashMapOf<Int, Int>();

        for (i in hours.indices) {
            if (hours[i] > 8) {
                sum++;
            } else {
                sum--;
            }

            if (sum > 0) {
                result = i + 1;
            } else {
                memo[sum - 1]?.let {
                    result = maxOf(result, i - it);
                }
            }

            if (!memo.contains(sum)) {
                memo[sum] = i;
            }
        }

        return result;
    }
}