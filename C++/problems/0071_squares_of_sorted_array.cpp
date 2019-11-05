//Problem Statement
// Given an array of integers A sorted in non-decreasing order,
// return an array of the squares of each number, also in sorted non-decreasing order.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        int start = 0, end = A.size()-1;
        while(start<=end){
            if(abs(A[start])<abs(A[end])){
                result.push_back(A[end]*A[end]);
                end--;
            }else{
                result.push_back(A[start]*A[start]);
                start++;
            }
        }

        reverse(result.begin(),result.end());
        return result;
    }
};

void printVec(vector<int> arr){
  for(auto val : arr)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<int> arr = {-7,-3,2,3,11};
  Solution sol;
  printVec(sol.sortedSquares(arr));
  return 0;
}
