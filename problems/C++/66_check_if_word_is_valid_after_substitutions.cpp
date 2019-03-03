//Problem Statement
// We are given that the string "abc" is valid.
//
// From any valid string V, we may split V into two pieces X and Y such that X + Y
// (X concatenated with Y) is equal to V.  (X or Y may be empty.)
// Then, X + "abc" + Y is also valid.
//
// If for example S = "abc", then examples of valid strings are: "abc", "aabcbc", "abcabc", "abcabcababcc".
// Examples of invalid strings are: "abccba", "ab", "cababc", "bac".
//
// Return true if and only if the given string S is valid.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string S) {
        stack<char> dfs;

        for(auto c : S){
            switch(c){
                case 'a':
                    dfs.push('a');
                    break;
                case 'b':
                    if(dfs.empty() || dfs.top()!='a')
                        return false;
                    dfs.pop();
                    dfs.push('b');
                    break;
                case 'c':
                    if(dfs.empty() || dfs.top()!='b')
                        return false;
                    dfs.pop();
                    break;
            }
        }

        return dfs.empty();
    }
};

int main(){
  string S = "abcabcababcc";
  Solution sol;
  cout<<sol.isValid(S)<<endl;
  return 0;
}
