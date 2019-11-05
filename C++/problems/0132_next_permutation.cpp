// Problem Statement
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int reverseIndex = nums.size()-1;
        while((reverseIndex-1)>=0 && nums[reverseIndex-1]>=nums[reverseIndex]){
            reverseIndex--;
        }

        if(reverseIndex>0){
            int swapIndex = reverseIndex;
            while(swapIndex<nums.size() && nums[swapIndex]>nums[reverseIndex-1]){
                swapIndex++;
            }
            swapIndex--;

            swap(nums[reverseIndex-1],nums[swapIndex]);
        }

        reverse(nums.begin()+reverseIndex, nums.end());
    }
};

void printVec(const vector<int> &vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> vec = {1,3,2,1};
    Solution sol;

    sol.nextPermutation(vec);
    printVec(vec);
    return 0;
}