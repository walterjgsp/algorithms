// Problem Statement
// Given a positive integer n and you can do operations as follow:
//
// If n is even, replace n with n/2.
// If n is odd, you can replace n with either n + 1 or n - 1.
// What is the minimum number of replacements needed for n to become 1?
package org.algorithm.problems

class `0041_integer_replacement`{
    var memo:HashMap<Int,Int> = HashMap<Int,Int>();
    fun integerReplacement(n: Int): Int {
        if(n==Int.MAX_VALUE)
            return 32;

        if(memo.contains(n))
            return memo.getValue(n);

        var minReplacement:Int = 0;

        if(n==1)
            return minReplacement;

        if(n%2==0){
            minReplacement = 1+integerReplacement(n/2);
        }else{
            minReplacement = 1+minOf(integerReplacement(n+1),integerReplacement(n-1));
        }

        memo.put(n,minReplacement);
        return minReplacement;
    }
}

