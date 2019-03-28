+++
title = "Word Break"
description = "Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words."
date = 2019-03-18T21:21:57-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/word-break/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given a non-empty string **s** and a dictionary wordDict containing a list of non-empty words, determine if **s** can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.

You may assume the dictionary does not contain duplicate words.

<h2 class="title is-5"> Solution </h2>

Starting from the end to the start, we break the string in two parts from. First check if the right most part is in the dictionary, if it is then check if the left most part is a sequence
of one or more words from the dictionary. If the both checks are true return true.

The trick of this problem is how to solve this in an optimized way. Is possible to use recursion with memoization since the problem presents **overlapping sub-problems** and **optimal substructure**.
Using a Hash Map we can reduce the complexity by avoiding the same data being processed more than one time.

{{< highlight cpp >}}
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
{{< /highlight >}}
