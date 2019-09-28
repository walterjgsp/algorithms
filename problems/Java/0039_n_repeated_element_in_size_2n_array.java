//Problem Statement
//In a array A of size 2N, there are N+1 unique elements, and exactly one of
//these elements is repeated N times.
/* Return the element repeated N times.
Example :

Input: [1,2,3,3]
Output: 3 */

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = {5,1,5,2,5,3,5,4};
        System.out.println(sol.repeatedNTimes(arr));
    }
}

class Solution {
    public int repeatedNTimes(int[] A) {
        HashSet<Integer> unique = new HashSet<Integer>();
        
        for(int i=0;i<A.length;i++){
            if(unique.contains(A[i])){
                return A[i];
            }
            
            unique.add(A[i]);
        }
        
        return 0;
    }
}