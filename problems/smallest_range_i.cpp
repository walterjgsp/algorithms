// Problem Statement

// Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
//
// After this process, we have some array B.
//
// Return the smallest possible difference between the maximum value of B and the minimum value of B.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
          int minVal = INT_MAX,maxVal = INT_MIN;
          if(A.size()<2)
            return 0;

          for(auto val : A){
              minVal = min(minVal,val);
              maxVal = max(maxVal,val);
          }

          if(maxVal-K<=minVal+K)
            return 0;

          return (maxVal-K)-(minVal+K);
    }
};

int main(){
  vector<int> temp = {2,7,2};
  Solution sol;
  cout<<sol.smallestRangeI(temp,1)<<endl;
  return 0;
}
