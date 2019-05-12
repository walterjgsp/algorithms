//Problem Statement
//Given an integer array A, you partition the array into (contiguous) 
//subarrays of length at most K.  After partitioning, each subarray has 
//their values changed to become the maximum value of that subarray.

//Return the largest sum of the given array after partitioning.
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int,int> memo;

public:    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        return helperMaxSum(A,K,A.size()-1);
    }
    
    int helperMaxSum(const vector<int> &A,const int &K, int index){
        if(memo.find(index)!=memo.end()){
            return memo[index];
        }
    
        if(index==0){
            return memo[index]=A[index];
        }
    
        int maxVal = INT_MIN,maxSum=0;
        for(int i=index;i>=0 && i>index-K;i--){
            maxVal = max(maxVal,A[i]);
            int rightSum = maxVal*(index-i+1);
            int leftSum = helperMaxSum(A,K,i-1);
            maxSum=max(maxSum,rightSum+leftSum);
        }
        
        return memo[index]=maxSum;
    }
};

int main(){
    vector<int> arr = {1,15,7,9,2,5,10};
    Solution sol;
    cout<<sol.maxSumAfterPartitioning(arr,3)<<endl;

    return 0;
}