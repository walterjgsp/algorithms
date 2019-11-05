// Problem Statement
// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    vector<vector<int>> result;

    void helper(const vector<int> &nums, const int &target, vector<int> &curr, int &currSum, int pos){
        if(currSum>target){
            return;
        }

        if(currSum == target){
            result.push_back(curr);
            return;
        }

        for(int i=pos+1;i<nums.size();i++){
            curr.push_back(nums[i]);
            currSum+=nums[i];
            helper(nums,target,curr,currSum,i);
            curr.pop_back();
            currSum-=nums[i];

            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        result.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        int currSum = 0;
        helper(candidates,target,curr,currSum,-1);
        return result;
    }
};

void printVec(vector<int> &vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution sol;
    vector<vector<int>> result = sol.combinationSum2(candidates,target);
    for(auto vec : result){
        printVec(vec);
    }
    return 0;
}