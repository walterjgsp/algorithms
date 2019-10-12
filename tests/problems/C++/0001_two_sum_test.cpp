#include "../../../problems/C++/0001_two_sum.hpp"
#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> vec){
  for(auto val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<int> vec = {2, 11, 7, 15};
  printVec(twoSum(vec,9));
  return 0;
}