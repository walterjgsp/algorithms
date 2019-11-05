//Problem Statement
//You're given strings J representing the types of stones that are jewels,
//Yand S representing the stones you have.  Each character in S is a type of
//Ystone you have.  You want to know how many of the stones you have are also jewels.
/*
The letters in J are guaranteed distinct, and all characters in J and S are
letters. Letters are case sensitive, so "a" is considered a different type of stone from "A". */

import java.util.*;

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.numJewelsInStones("aA","aAAbbbb"));
    }
}

class Solution {
    public int numJewelsInStones(String J, String S) {
        int result = 0;
        HashSet<Character> count = new HashSet<Character>();
        
        for(int i=0;i<J.length();i++){
            count.add(J.charAt(i));
        }
        
        for(int i=0;i<S.length();i++){
            if(count.contains(S.charAt(i))){
                result++;
            }
        }
        
        return result;
    }
}