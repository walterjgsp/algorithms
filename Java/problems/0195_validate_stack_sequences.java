// Problem Statement
// Given two integer arrays pushed and popped each with distinct values,
// return true if this could have been the result of a sequence of push
// and pop operations on an initially empty stack, or false otherwise.

import java.util.Stack;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {

        Stack<Integer> stack = new Stack<Integer>();
        int currentPops = 0;

        for (int item : pushed) {

            stack.push(item);

            while (!stack.isEmpty() && stack.peek() == popped[currentPops]) {
                stack.pop();
                currentPops++;
            }
        }

        return stack.isEmpty();
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        // true
        System.out.println(solution.validateStackSequences(new int[] { 1, 2, 3, 4, 5 }, new int[] { 4, 5, 3, 2, 1 }));
        // false
        System.out.println(solution.validateStackSequences(new int[] { 1, 2, 3, 4, 5 }, new int[] { 4, 3, 5, 1, 2 }));
    }
}