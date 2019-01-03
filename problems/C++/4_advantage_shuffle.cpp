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

        for(int i=0;i<A.size();i++){
            helperB.push_back(make_pair(B[i],i));
        }

        sort(A.begin(),A.end());
        sort(helperB.begin(),helperB.end());

        vector<int> to_return (A.size(),INT_MIN), to_add;

        int i=0,j=0;

        while(i<A.size() && j<helperB.size()){
            if(A[i]<=helperB[j].first){
                to_add.push_back(A[i]);
                i++;
            }else{
                to_return[helperB[j].second]=A[i];
                i++;
                j++;
            }
        }

        int index = 0;
        for(int i=0;i<to_return.size();i++){

            if(index>=to_add.size())
                break;

            if(to_return[i]==INT_MIN){
                to_return[i]=to_add[index];
                index++;
            }
        }

        return to_return;
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
