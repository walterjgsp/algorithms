// Problem Statement

// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
// Input:  [0,1,2,4,5,7,9,10]
// Output: ["0->2","4->5","7","9->10"]
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> to_return;
        if(nums.empty())
            return to_return;

        vector<vector<int>> helper;

        helper.push_back({nums[0]});

        for(int i=1;i<nums.size();i++){
            if(nums[i]-helper.back().back()==1){
                helper.back().push_back(nums[i]);
            }else{
                helper.push_back({nums[i]});
            }
        }

        for(auto vec:helper){
            string temp;
            if(vec.size()==1){
                temp=to_string(vec.back());
            }else{
                temp=to_string(vec[0])+"->"+to_string(vec.back());
            }

            to_return.push_back(temp);
        }

        return to_return;
    }
};

template <class T>
void printVec(const vector<T> vec){
  cout<<"["<<vec[0];
  for(int i=1;i<vec.size();i++){
    cout<<","<<vec[i];
  }
  cout<<"]"<<endl;
}

int main(){

  Solution sol;
  vector<int> temp = {1,2,3,5,7,8,9,11};
  printVec(sol.summaryRanges(temp));
  return 0;
}
