// Problem Statement

// Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
//
// After this process, we have some array B.
//
// Return the smallest possible difference between the maximum value of B and the minimum value of B.
class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = {1,3,6};
        System.out.println(sol.smallestRangeI(arr,3));
    }
}

class Solution {
    public int smallestRangeI(int[] A, int K) {
        
        int maxVal = A[0], minVal = A[0];
        
        for(int i=1;i<A.length;i++){
            maxVal = Math.max(A[i],maxVal);
            minVal = Math.min(A[i],minVal);
        }
        
        if((maxVal-K)<=(minVal+K)){
            return 0;
        }else{
            return (maxVal-K)-(minVal+K);
        }
        
    }
}