// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

class Solution {
    public boolean canJump(int[] nums) {
        int lastGoodPosition = nums.length - 1;
        for (int i = lastGoodPosition; i >= 0; i--) {
            // Can get to lastGoodPosition?
            if (i + nums[i] >= lastGoodPosition) {
                lastGoodPosition = i;
            }
        }
        return lastGoodPosition == 0;
    }
}

class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = new int[] { 3, 2, 1, 0, 4 };
        System.out.println(sol.canJump(nums));
        nums = new int[] { 2, 3, 1, 1, 4 };
        System.out.println(sol.canJump(nums));
    }
}
