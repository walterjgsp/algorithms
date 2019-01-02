//Problem Statement
// Suppose an array sorted in ascending order is rotated at some pivot unknown to
// you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int init = 0, end = nums.size();

        while(init<end){
          int mid = init + (end-init)/2;

          if(nums[mid]>nums.back()){
            init = mid+1;
          }else{
            end = mid;
          }
        }

        return nums[init];
    }
};

int main(){
  vector<int> vec = {4,5,6,7,0,1,2};
  Solution sol;

  cout<<sol.findMin(vec);

  return 0;
}
