// Problem Statement
// A string is said to be a child of a another string if it can be formed by deleting
// 0 or more characters from the other string. Given two strings of equal length,
// what's the longest string that can be constructed such that it is a child of both?
//
// For example, ABCD and ABDC have two children with maximum length 3, ABC and ABD.
// They can be formed by eliminating either the D or C from both strings.
// Note that we will not consider ABCD as a common child because we can't
// rearrange characters and ABCD!= ABDC.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
  int commonChild(string s1, string s2) {
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
};

int main(){
  string s1 = "SHINCHAN",s2="NOHARAAA";
  Solution sol;
  cout<<sol.commonChild(s1,s2)<<endl;
  return 0;
}
