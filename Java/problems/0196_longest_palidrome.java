// Problem Statement
// Given a string s which consists of lowercase or uppercase letters,
// return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

import java.util.Set;
import java.util.HashSet;

class Solution {
    public int longestPalindrome(String s) {
        Set<Character> unpaired = new HashSet<Character>();
        int pairs = 0;
        
        for(Character c : s.toCharArray()){
            if(unpaired.contains(c)){
                pairs++;
                unpaired.remove(c);
            } else {
                unpaired.add(c);
            }
        }

        return unpaired.isEmpty() ? pairs*2 : pairs*2+1;    
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome("abccccdd"));
        System.out.println(solution.longestPalindrome("aa"));
        System.out.println(solution.longestPalindrome("b"));
    }
}