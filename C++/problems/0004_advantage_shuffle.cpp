//Problem Statement
// Given two arrays A and B of equal size, the advantage of A with
// respect to B is the number of indices i for which A[i] > B[i].
//
// Return any permutation of A that maximizes its advantage with respect to B.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      vector<pair<int,int>> helperB;
      vector<int> result (A.size(),-1);
      int tam = A.size();

      for(int i=0;i<tam;i++){
          helperB.push_back(make_pair(B[i],i));
      }

      sort(A.begin(),A.end());
      sort(helperB.begin(),helperB.end());

      int indexA = 0,indexB = 0;

      while(indexA<tam){
          auto pairB = helperB[indexB];
          if(A[indexA]>pairB.first){
              result[pairB.second]=A[indexA];
              A[indexA]=-1;
              indexB++;
          }
          indexA++;
      }

      indexA = 0;
      int i = 0;

      while(indexA<tam && i<tam){
          if(A[indexA]==-1){
              indexA++;
          }else if(result[i]!=-1){
              i++;
          }else{
              result[i]=A[indexA];
              i++;
              indexA++;
          }
      }

      return result;
    }
};

void printVec(const vector<int> &vec){
  for(int val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<int> A = {2,7,11,15}, B ={1,10,4,11};
  Solution sol;

  printVec(sol.advantageCount(A,B));
  return 0;
}
