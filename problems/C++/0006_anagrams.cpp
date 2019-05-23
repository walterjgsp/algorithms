//Problem Statement

// Given two strings, a and b , that may or may not be of the same length,
// determine the minimum number of character deletions required to make a and b anagrams.
// Any characters can be deleted from either of the strings.

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

    int getMinimumDeletionsToAnagram(string s1, string s2){
      vector<int> count(256,0);
      int result =0;
      for(auto c:s1){
        count[c-'a']++;
      }

      for(auto c:s2){
        count[c-'a']--;
      }

      for(auto val : count){
        result+=abs(val);
      }

      return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.getMinimumDeletionsToAnagram("cde","abc")<<endl;

    return 0;
}
