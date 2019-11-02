// Problem Statement
// A sequence of number is called arithmetic if it consists of at least three elements and
// if the difference between any two consecutive elements is the same.
//
// For example, these are arithmetic sequence:
//
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.
//
// 1, 1, 2, 5, 7
//
// A zero-indexed array A consisting of N numbers is given. A slice of that array is
// any pair of integers (P, Q) such that 0 <= P < Q < N.
//
// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
//
// The function should return the number of arithmetic slices in the array A.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3)
            return 0;
        int result = 0;
        int diff = A[1]-A[0];
        int left = 0,right;

        for(right=2;right<=A.size();right++){
            if(right==A.size() || A[right]-A[right-1]!=diff){
                int counter = 1;
                while(right-left>=3){
                    result+=counter;
                    counter++;
                    left++;
                }
                if(right<A.size())
                    diff = A[right]-A[right-1];
                left = right-1;
            }
        }

        return result;
    }
};

int main(){
  vector<int> arr = {1,2,3,4,2,6};
  Solution sol;
  cout<<sol.numberOfArithmeticSlices(arr)<<endl;
  return 0;
}
