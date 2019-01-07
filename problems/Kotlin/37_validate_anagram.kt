//Problem Statement
//Given two strings s and t , write a function to determine if t is an anagram of s.

class Solution constructor() {
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

fun main(args:Array<String>){
  var s:String = "anagram";
  var t:String = "nagaram";
  var sol : Solution = Solution();
  println(sol.isAnagram(s,t));
}
