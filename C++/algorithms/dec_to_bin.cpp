#include <bits/stdc++.h>
using namespace std;

string decToBin(int N){
  string res = "";
  while(N){
    res = to_string(N&1)+res;
    N>>=1;
  }
  return res== "" ? "0" : res;
}

int main(){
  cout<<decToBin(2)<<endl;
  cout<<decToBin(10)<<endl;
  cout<<decToBin(64)<<endl;
  return 0;
}
