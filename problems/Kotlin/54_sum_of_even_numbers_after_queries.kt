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

class Solution constructor() {
    fun sumEvenAfterQueries(A: IntArray, queries: Array<IntArray>): IntArray {
        var result:MutableList<Int> = mutableListOf<Int>();
        var evenSum: Int = 0;

        for(value in A){
            if(value%2==0){
                evenSum += value;
            }
        }

        for(query in queries){
            if(A[query[1]]%2==0){
                evenSum-=A[query[1]];
            }

            A[query[1]]+=query[0];

            if(A[query[1]]%2==0){
                evenSum+=A[query[1]];
            }

            result.add(evenSum);
        }

        return result.toIntArray();
    }
}

fun main(args:Array<String>){
  var sol:Solution = Solution();
  var A: IntArray = intArrayOf(1,2,3,4);
  var queries:Array<IntArray> = arrayOf(intArrayOf(1,0),intArrayOf(-3,1),intArrayOf(-4,0),intArrayOf(2,3));
  println(sol.sumEvenAfterQueries(A,queries).joinToString(prefix = "[", postfix = "]"));
}
