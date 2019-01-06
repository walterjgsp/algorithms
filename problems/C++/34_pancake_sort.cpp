//Problem Statement
// Given an array A, we can perform a pancake flip:
// We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.
// We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
//
// Return the k-values corresponding to a sequence of pancake flips that sort A.
// Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        return res;
    }
};

void printVec(const vector<int> &vec){
  for(auto val : vec){
    cout<<val<<" ";
  }
  cout<<endl;
}

int main(){
  // vector<int> vec = {3,2,4,1};
  vector<int> vec = {10,5,1,6,3,8,2,4,7,9};
  Solution sol;
  printVec(vec);
  printVec(sol.pancakeSort(vec));
  return 0;
}
