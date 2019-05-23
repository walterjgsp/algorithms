// Problem Statement
// We have an array A of integers, and an array queries of queries.
//
// For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].
// Then, the answer to the i-th query is the sum of the even values of A.
//
// (Here, the given index = queries[i][1] is a 0-based index, and each query permanently
// modifies the array A.)
//
// Return the answer to all queries.  Your answer array should have answer[i]
// as the answer to the i-th query.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        int actual_sum = 0;

        for(auto value:A){
            if(value%2==0)
                actual_sum+=value;
        }

        for(auto query : queries){
            int position = query[1], to_sum = query[0];

            if(A[position]%2==0)
                actual_sum-=A[position];

            A[position]+=to_sum;

            if(A[position]%2==0)
                actual_sum+=A[position];

            result.push_back(actual_sum);
        }

        return result;
    }
};

void printVec(vector<int> vec){
  for(auto val : vec){
    cout<<val<<" ";
  }
  cout<<endl;
}

int main(){
  Solution sol;
  vector<int> A = {1,2,3,4};
  vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
  printVec(sol.sumEvenAfterQueries(A,queries));
  return 0;
}
