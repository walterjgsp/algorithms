// Proble Statement
//
// A zero-indexed array A of length N contains all integers from 0 to N-1.
// Find and return the longest length of set S,
// where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
//
// Suppose the first element in S starts with the selection of element A[i]
// of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]…
// By that analogy, we stop adding right before a duplicate element occurs in S.
//
// Example:
// Input: A = [5,4,0,3,1,6,2]
// Output: 4
// Explanation:
// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
//
// One of the longest S[K]:
// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
package org.algorithm.problems

class `0008_array_nesting` {
    fun arrayNesting(nums: IntArray): Int {
        val visited: HashSet<Int> = HashSet<Int>();
        var result: Int = 0;

        for (index in nums.indices) {
            if (!visited.contains(index)) {
                val dfs: ArrayList<Int> = ArrayList<Int>();
                var actual_counter: Int = 0;
                dfs.add(index);

                while (!dfs.isEmpty()) {
                    val last: Int = dfs.last();
                    dfs.removeAt(dfs.size - 1);

                    if (!visited.contains(last)) {
                        visited.add(last);
                        dfs.add(nums[last]);
                        actual_counter++;
                    }
                }

                result = maxOf(result, actual_counter);
            }
        }

        return result;
    }
}