//Problem Statement

// Given an array A of non-negative integers,
// return an array consisting of all the even elements of A, followed by all the odd elements of A.
//
// You may return any answer array that satisfies this condition.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
      vector<int> odd,even;
      for(auto num : A){
          if(num%2)
              odd.push_back(num);
          else
              even.push_back(num);
      }

      even.insert(even.end(),odd.begin(),odd.end());

      return even;
    }

    vector<int> sortArrayByParityInPlace(vector<int>& A) {
      int start = 0, end = A.size()-1;

      while(start<end){
          if(A[start]%2!=0 && A[end]%2==0){
              swap(A[start],A[end]);
              start++;
              end--;
          }

          if(A[start]%2 == 0){
              start++;
          }

          if(A[end]%2 != 0){
              end--;
          }
      }

      return A;
    }
};

void printVec(const vector<int> & vec){
  for(auto val:vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<int> arr = {4,1,9,2,8,6,5};
  Solution sol;
  printVec(sol.sortArrayByParity(arr));
  return 0;
}
