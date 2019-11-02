// Problem Statement
//
// Given a sorted array consisting of only integers where every element appears
// twice except for one element which appears once. Find this single element that
// appears only once.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int start = 0,end=nums.size()-1;

    while(start<end){
      int mid = start + (end-start)/2;

      if(nums[mid]==nums[mid-1]){
        int left_size = mid-start+1;

        if(left_size%2!=0){
          end=mid;
        }else{
          start=mid+1;
        }
      }else if(nums[mid]==nums[mid+1]){
        int left_size = mid-start;

        if(left_size%2!=0){
          end=mid-1;
        }else{
          start=mid;
        }

      }else
        return nums[mid];
    }

    return nums[start];
  }
};

int main(){
  Solution sol;
  vector<int> vec = {0,0,1,1,2,3,3,4,4,5,5};
  cout<<sol.singleNonDuplicate(vec)<<endl;
  return 0;
}
