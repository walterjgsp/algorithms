// Problem Statement
// We have an array A of integers, and an array queries of queries.
//
// For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].
// Then, the answer to the i-th query is the sum of the even values of A.
//
// (Here, the given index = queries[i][1] is a 0-based index, and each query permanently
// modifies the array A.)
//
// Return the answer to all queries.  Your answer array should have answer[i]
// as the answer to the i-th query.
package org.algorithm.problems

class `0054_sum_of_even_numbers_after_queries` {
    fun sumEvenAfterQueries(A: IntArray, queries: Array<IntArray>): IntArray {
        val result: MutableList<Int> = mutableListOf<Int>();
        var evenSum: Int = 0;

        for (value in A) {
            if (value % 2 == 0) {
                evenSum += value;
            }
        }

        for (query in queries) {
            if (A[query[1]] % 2 == 0) {
                evenSum -= A[query[1]];
            }

            A[query[1]] += query[0];

            if (A[query[1]] % 2 == 0) {
                evenSum += A[query[1]];
            }

            result.add(evenSum);
        }

        return result.toIntArray();
    }
}