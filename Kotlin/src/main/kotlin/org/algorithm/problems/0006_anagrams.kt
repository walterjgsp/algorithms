//Problem Statement

// Given two strings, a and b , that may or may not be of the same length,
// determine the minimum number of character deletions required to make a and b anagrams.
// Any characters can be deleted from either of the strings.
package org.algorithm.problems

import java.lang.Math;

class `0006_anagrams`{
    fun getMinimumDeletionsToAnagram(A : String, B:String): Int {
      var countA:IntArray = IntArray(26) ;
      var countB:IntArray = IntArray(26) ;
      var result:Int = 0;

      for(letter in A){
        countA[letter-'a']++;
      }

      for(letter in B){
        countB[letter-'a']++;
      }

      for(index in 0..countA.size-1){
        result+=Math.abs(countA[index]-countB[index]);
      }

      return result;
    }
}
