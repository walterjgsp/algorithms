//Problem Statement
//Given two strings s and t , write a function to determine if t is an anagram of s.
package org.algorithm.problems

class `0037_validate_anagram` {
    fun isAnagram(s: String, t: String): Boolean {
        var counter: IntArray = IntArray(26) { i-> 0};

        for(letter in s){
            counter[letter-'a']++;
        }

        for(letter in t){
            counter[letter-'a']--;
        }

        for(count in counter){
            if(count!=0)
                return false;
        }

        return true;
    }
}
