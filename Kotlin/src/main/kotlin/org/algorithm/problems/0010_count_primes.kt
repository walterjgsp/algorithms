// Problem Statement

// Count the number of prime numbers less than a non-negative number, n.
package org.algorithm.problems

class `0010_count_primes` {
    fun countPrimes(n: Int): Int {
        var primes:BooleanArray = BooleanArray(n) { i -> true }
        var result:Int = 0;

        for (i in 2..n-1){
            if(primes[i]){
                var j:Int = 2;
                result++;
                while(j*i <= n-1 ){
                    primes[j*i]=false;
                    j++;
                }
            }
        }

        return result;
    }
}
