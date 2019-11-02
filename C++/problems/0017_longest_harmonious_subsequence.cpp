//Problem Statement
// We define a harmonious array is an array where the difference between its
// maximum value and its minimum value is exactly 1.
//
// Now, given an integer array, you need to find the length of its longest
// harmonious subsequence among all its possible subsequences.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> value_counter;
        int result=0;

        for(auto val : nums){
            value_counter[val]++;
        }

        for(auto it : value_counter){

            if(value_counter.find(it.first+1)!=value_counter.end()){
                result = max(result,it.second+value_counter[it.first+1]);
            }
        }

        return result;
    }
};

int main(){
  vector<int> vec = {1,3,2,2,5,2,3,7};
  Solution sol;
  cout<<sol.findLHS(vec)<<endl;
  return 0;
}
