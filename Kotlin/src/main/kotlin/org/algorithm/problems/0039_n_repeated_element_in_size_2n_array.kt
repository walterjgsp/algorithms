//Problem Statement
//In a array A of size 2N, there are N+1 unique elements, and exactly one of
//these elements is repeated N times.
/* Return the element repeated N times.
Example :

Input: [1,2,3,3]
Output: 3 */
package org.algorithm.problems

class `0039_n_repeated_element_in_size_2n_array` {
    fun repeatedNTimes(A: IntArray): Int {
        var unique:HashSet<Int> = HashSet<Int>();

        for( value in A){
            if(unique.contains(value)){
                return value;
            }
            unique.add(value);
        }

        return 0;
    }
}