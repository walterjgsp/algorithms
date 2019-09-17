class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(sol.maxSubArray(arr));
    }
}

class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = nums[0], maxSum = nums[0];
        for(int i=1;i<nums.length;i++){
            currSum = Math.max(currSum+nums[i],nums[i]);
            maxSum = Math.max(maxSum,currSum);
        }

        return maxSum;
    }
}
