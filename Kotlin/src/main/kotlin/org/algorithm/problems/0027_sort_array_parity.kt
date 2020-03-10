//Problem Statement

// Given an array A of non-negative integers,
// return an array consisting of all the even elements of A, followed by all the odd elements of A.
//
// You may return any answer array that satisfies this condition.
package org.algorithm.problems

class `0027_sort_array_parity` {
    fun sortArrayByParity(A: IntArray): IntArray {
        var even:MutableList<Int> = mutableListOf();
        var odd:MutableList<Int> = mutableListOf();

        for(num in A){
            if(num%2==0)
                even.add(num);
            else
                odd.add(num);
        }

        even.addAll(odd);
        return even.toIntArray();
    }
}
