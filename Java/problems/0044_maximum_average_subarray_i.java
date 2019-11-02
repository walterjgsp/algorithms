//Problem Statement
//Given an array consisting of n integers, find the contiguous
//subarray of given length k that has the maximum average value.
//And you need to output the maximum average value.
class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = {5,1,5,2,5,3,5,4};
        System.out.println(sol.findMaxAverage(arr,4));
    }
}

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int start = 0;
        double result = Integer.MIN_VALUE, curr = 0;
        
        for(int i=0;i<nums.length;i++){
            if(i<k-1){
                curr+=nums[i];
            }else{
                curr+=nums[i];
                result = Math.max(result,curr/k);
                curr-=nums[start];
                start++;
            }
        }
        
        return result;
    }
}