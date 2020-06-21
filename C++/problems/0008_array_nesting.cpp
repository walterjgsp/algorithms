// Problem Statement
//
// A zero-indexed array A of length N contains all integers from 0 to N-1.
// Find and return the longest length of set S,
// where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
//
// Suppose the first element in S starts with the selection of element A[i]
// of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]…
// By that analogy, we stop adding right before a duplicate element occurs in S.
//
// Example:
// Input: A = [5,4,0,3,1,6,2]
// Output: 4
// Explanation:
// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
//
// One of the longest S[K]:
// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> pool(nums.begin(),nums.end());
        int to_return=0;


        for(int i=0;i<nums.size();i++){

            int it = nums[i];
            int actual = 0;

            while(pool.find(it)!=pool.end()){

                pool.erase(it);
                actual++;
                it = nums[it];
            }

            to_return = max(to_return,actual);
        }

        return to_return;
    }
};

int main(){
  Solution sol;
  vector<int> input = {5,4,0,3,1,6,2};
  cout<<sol.arrayNesting(input)<<endl;
  return 0;
}
