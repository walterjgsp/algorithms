//Problem Statement
// Return all non-negative integers of length N such that the
// absolute difference between every two consecutive digits is K.
//
// Note that every number in the answer must not have leading zeros except for
// the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.
//
// You may return the answer in any order.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void helper(set<int> &result,int N, const int &K,int actual){
        if(N==0){
            result.insert(actual);
            return;
        }

        int last_digit = actual%10;
        if(last_digit-K>=0){
            helper(result,N-1,K,actual*10+last_digit-K);
        }

        if(last_digit+K<10){
            helper(result,N-1,K,actual*10+last_digit+K);
        }

    }
    vector<int> numsSameConsecDiff(int N, int K) {
        set<int> temp_result;
        if(N==1)
            temp_result.insert(0);
        for(int i=1;i<10;i++){
            helper(temp_result,N-1,K,i);
        }

        vector<int> to_return(temp_result.begin(),temp_result.end());
        return to_return;
    }
};

void printVec(vector<int> vec){
  for(auto val:vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  int N=3,K=7;
  Solution sol;
  vector<int> result = sol.numsSameConsecDiff(N,K);
  printVec(result);
  return 0;
}
