// Problem Statement
// Given a positive integer n and you can do operations as follow:
//
// If n is even, replace n with n/2.
// If n is odd, you can replace n with either n + 1 or n - 1.
// What is the minimum number of replacements needed for n to become 1?

import java.util.*;

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.integerReplacement(1443));
    }
}

class Solution {
    private HashMap<Integer,Integer> memo;
    
    Solution(){
        memo = new HashMap<Integer,Integer>();
    }
    
    public int integerReplacement(int n) {
        if(n==Integer.MAX_VALUE){
            return 32;
        }
        if(!memo.containsKey(n)){
            int minReplacement = 0;
            if(n>1){
                if(n%2==0){
                    minReplacement = 1+integerReplacement(n/2);
                }else{
                    minReplacement = 1+Math.min(integerReplacement(n+1),integerReplacement(n-1));
                }    
            }
            memo.put(n,minReplacement);
        }
        
        return memo.get(n);
    }
}