// Problem Statement
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool helperWordBreak(unordered_map<string,bool> &memo,const unordered_set<string> &dict, string word){
    if(memo.find(word)!=memo.end())
            return memo[word];

    if(dict.find(word)!=dict.end())
            return memo[word]=true;

    for(int i=word.size()-1; i>0; i--) {

            string right = word.substr(i);
            if(dict.find(right)==dict.end())
                    continue;

            string left = word.substr(0,i);
            if(helperWordBreak(memo,dict,left)) {
                    return memo[word]=true;
            }
    }

    return memo[word]=false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict (wordDict.begin(),wordDict.end());
    unordered_map<string,bool> memo;

    return helperWordBreak(memo,dict,s);
  }
};

int main(){
  string s = "applepenapple";
  vector<string> wordDict = {"apple", "pen"};
  Solution sol;
  cout<<sol.wordBreak(s,wordDict)<<endl;

  return 0;
}
