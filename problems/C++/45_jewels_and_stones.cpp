//Problem Statement
//You're given strings J representing the types of stones that are jewels,
//Yand S representing the stones you have.  Each character in S is a type of
//Ystone you have.  You want to know how many of the stones you have are also jewels.
/*
The letters in J are guaranteed distinct, and all characters in J and S are
letters. Letters are case sensitive, so "a" is considered a different type of stone from "A". */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
      vector<int> counter (256);
      int result = 0;

      for(auto jewel : J){
        counter[jewel]++;
      }

      for(auto stone: S){
        if(counter[stone]>0)
          result++;
      }

      return result;
    }
};

int main(){
  string J = "aA", S = "aAAbbbb";
  Solution sol;
  cout<<sol.numJewelsInStones(J,S)<<endl;
  return 0;
}
