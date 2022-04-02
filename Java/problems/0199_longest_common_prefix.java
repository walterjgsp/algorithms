// Problem Statement
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        char[] prefix = strs[0].toCharArray();

        for (int i = 1; i < strs.length; i++) {
            char[] word = strs[i].toCharArray();

            for (int j = 0; j < prefix.length; j++) {
                if (word.length <= j || prefix[j] != word[j])
                    prefix = Arrays.copyOfRange(prefix, 0, j);
            }
        }

        return String.valueOf(prefix);
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] flList = { "flower", "flow", "flight" };
        String[] emptyResponseList = { "dog", "racecar", "car" };

        System.out.println(solution.longestCommonPrefix(flList));
        System.out.println(solution.longestCommonPrefix(emptyResponseList));
    }
}
