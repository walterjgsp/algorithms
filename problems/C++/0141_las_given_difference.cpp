// Problem Statement
// Given an integer array arr and an integer difference, return the length of the 
// longest subsequence in arr which is an arithmetic sequence such that the difference 
// between adjacent elements in the subsequence equals difference.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> memo;
        int result = 1;
        for(int i=0;i<arr.size();i++){
            int key = arr[i]-difference;
            int curr = 1;
            if(memo.find(key)!=memo.end()){
                curr=max(1,memo[key]+1);
            }
            memo[arr[i]]=max(memo[arr[i]],curr);
            result = max(result,memo[arr[i]]);
        }
        
        return result;
    }
};

int main(){
    vector<int> arr = {1,5,7,8,5,3,4,2,1};
    Solution sol;
    cout<<sol.longestSubsequence(arr,-2)<<endl;
    return 0;
}