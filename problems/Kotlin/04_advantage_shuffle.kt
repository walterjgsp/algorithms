//Problem Statement
// Given two arrays A and B of equal size, the advantage of A with
// respect to B is the number of indices i for which A[i] > B[i].
//
// Return any permutation of A that maximizes its advantage with respect to B.

class Solution {
    fun advantageCount(A: IntArray, B: IntArray): IntArray {
        var result:IntArray = IntArray(A.size) { i -> -1};
        var helperB:MutableList<Pair<Int,Int>> = mutableListOf<Pair<Int,Int>>();
        var to_add: MutableList<Int> = mutableListOf<Int>();

        for(i in B.indices){
            helperB.add(Pair(B[i],i));
        }

        A.sort();
        helperB.sortWith(compareBy({it.first}));

        var indexA: Int = 0;
        var indexB: Int = 0;

        while(indexA < A.size){
            if(A[indexA]>helperB[indexB].first){
                result[helperB[indexB].second]=A[indexA];
                indexB++;
            }else{
                to_add.add(A[indexA]);
            }
            indexA++;
        }

        indexA = 0;

        for(i in to_add.indices){
            while(result[indexA]>=0){
                indexA++;
            }
            result[indexA]=to_add[i];
        }

        return result;
    }
}

fun main(args:Array<String>){
  val numsA: IntArray = intArrayOf(2,7,11,15);
  val numsB: IntArray = intArrayOf(1,10,4,11);
  val sol:Solution = Solution();
  println(sol.advantageCount(numsA,numsB).joinToString(prefix = "[", postfix = "]"));
}
