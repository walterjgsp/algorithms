// Problem Statement
// Given an array A of positive integers, A[i] represents the value of the i-th
// sightseeing spot, and two sightseeing spots i and j have distance j - i between them.
//
// The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) :
// the sum of the values of the sightseeing spots, minus the distance between them.
//
// Return the maximum score of a pair of sightseeing spots.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int result = INT_MIN;
        vector<int> dp(A.size(),0);

        dp.back() = A.back();

        for(int i=A.size()-2;i>=0;i--){
            dp[i]=max(A[i],dp[i+1]-1);
        }

        for(int i=0;i<A.size()-1;i++){
            result = max(result,A[i]+dp[i+1]-1);
        }

        return result;
    }
};

int main(){
  vector<int> A = {8,1,5,2,8,6};
  Solution sol;
  cout<<sol.maxScoreSightseeingPair(A)<<endl;
  return 0;
}
