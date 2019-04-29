// Longest Common Subsequence
// LCS Problem Statement: Given two sequences, find the length of longest subsequence
// present in both of them. A subsequence is a sequence that appears in the same relative order,
// but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc
// are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.
#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
  vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1));

  for(int i=1;i<=s1.size();i++){
      for(int j=1;j<=s2.size();j++){
          if(s1[i-1]==s2[j-1]){
              dp[i][j] = 1 + dp[i-1][j-1];
          }else{
              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
          }
      }
  }

  return dp.back().back();
}

int main(){
  string s1 = "123321",s2="321123";
  Solution sol;
  cout<<lcs(s1,s2)<<endl;
  return 0;
}
