// Problem Statement
// Given a string s, return the longest palindromic substring in s.

import java.util.Set;
import java.util.HashSet;

class Solution {
    public String longestPalindrome(String s) {

        int length = s.length();
        String answer = "";
        int max = 0;

        boolean[][] memory = new boolean[length][length];

        // Build a grid with every substring starting at every index of the string
        for (int column = 0; column < length; column++) {

            if (max == length) {
                break;
            }

            for (int row = 0; row <= column; row++) {

                boolean isPalindrome = s.charAt(row) == s.charAt(column);

                // if is more than 2 characters, then check if the middle if palindrome
                if (isPalindrome && (column - row) > 2) {
                    isPalindrome = isPalindrome && memory[row + 1][column - 1];
                }

                memory[row][column] = isPalindrome;

                if (isPalindrome && column - row + 1 > max) {
                    max = column - row + 1;
                    answer = s.substring(row, column + 1);
                }

            }
        }

        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        // bab
        System.out.println(solution.longestPalindrome("babad"));
        // bb
        System.out.println(solution.longestPalindrome("cbbd"));
    }
}
