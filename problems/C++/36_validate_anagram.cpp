//Problem Statement
//Given two strings s and t , write a function to determine if t is an anagram of s.

#include <bits/stdc++.h>

using namespace std;

class Solution{
  bool isAnagram(string s, string t){
    vector<int> counter (26,0);

    for(auto letter : s){
      counter[letter-'a']++;
    }

    for(auto letter : t){
      counter[letter-'a']--;
    }

    for(auto count : counter){
      if(count!=0)
        return false;
    }

    return true;
  }
};

int main(){
  string s = "anagram", t = "nagaram";
  Solution sol;
  cout<<sol.isAnagram(s,t)<<endl;
  return 0;
}
