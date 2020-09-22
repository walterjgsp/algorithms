// Problem Statement
// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(candidates);
        findCombinations(candidates, 0, target, new ArrayList<>(), result);
        return result;
    }

    private void findCombinations(int[] candidates, int index, int target, List<Integer> current,
            List<List<Integer>> result) {
        if (target < 0)
            return;
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = index; i < candidates.length; i++) {
            // Pick a value
            if (shouldPìckValue(candidates, index, i, target)) {
                current.add(candidates[i]);
                findCombinations(candidates, i + 1, target - candidates[i], current, result);
                // backtracks to try other values
                current.remove(current.size() - 1);
            }
        }

    }

    private boolean shouldPìckValue(int[] candidates, int index, int i, int target) {
        if (i == index || candidates[i] != candidates[i - 1]) {
            return target - candidates[i] >= 0;
        }
        return false;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] candidates = { 10, 1, 2, 7, 6, 1, 5 };
        int target = 8;
        System.out.println(solution.combinationSum2(candidates, target));
    }
}