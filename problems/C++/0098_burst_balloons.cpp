//Problem Statement
//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a 
//number on it represented by array nums. You are asked to burst all the balloons. 
//If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
//Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

//Find the maximum coins you can collect by bursting the balloons wisely.
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<pair<int,int>,int> memo;

    int burstCost(const vector<int> &nums, int i,int j){
        pair<int,int> key = {i,j};
        
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
                
        int result = 0,multLeft=1,multRight=1;
        if(i>0){
            multLeft=nums[i-1];
        }
        
        if(j<nums.size()-1){
            multRight=nums[j+1];
        }
        
        if(i==j){
            return memo[key] =  multLeft*nums[i]* multRight;
        }
        
        for(int k=i;k<=j;k++){
            int left = 0, right =0;
            if(k!=i){
                left = burstCost(nums,i,k-1);
            }
            
            if(k!=j){
                right = burstCost(nums,k+1,j);
            }
                        
            int curr =  multLeft* nums[k] * multRight;
            result = max(result,left+right+curr);
        }
        
        return memo[key]=result;
    }
public:
    int maxCoins(vector<int>& nums) {
        return burstCost(nums,0,nums.size()-1);
    }    
};

int main(){
    vector<int> nums = {3,1,5,8};
    Solution sol;
    cout<<sol.maxCoins(nums)<<endl;
    return 0;
}