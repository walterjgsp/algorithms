//Problem Statement
// Given two arrays A and B of equal size, the advantage of A with
// respect to B is the number of indices i for which A[i] > B[i].
//
// Return any permutation of A that maximizes its advantage with respect to B.
package org.algorithm.problems

class `0004_advantage_shuffle` {
    fun advantageCount(A: IntArray, B: IntArray): IntArray {
        val result: IntArray = IntArray(A.size) { i -> -1 };
        val helperB: MutableList<Pair<Int, Int>> = mutableListOf<Pair<Int, Int>>();
        val to_add: MutableList<Int> = mutableListOf<Int>();

        for (i in B.indices) {
            helperB.add(Pair(B[i], i));
        }

        A.sort();
        helperB.sortWith(compareBy({ it.first }));

        var indexA: Int = 0;
        var indexB: Int = 0;

        while (indexA < A.size) {
            if (A[indexA] > helperB[indexB].first) {
                result[helperB[indexB].second] = A[indexA];
                indexB++;
            } else {
                to_add.add(A[indexA]);
            }
            indexA++;
        }

        indexA = 0;

        for (i in to_add.indices) {
            while (result[indexA] >= 0) {
                indexA++;
            }
            result[indexA] = to_add[i];
        }

        return result;
    }
}