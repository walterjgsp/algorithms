//Problem Statement
// Given two words word1 and word2, find the minimum number of operations required
// to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
// Insert a character
// Delete a character
// Replace a character
#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
  map<pair<int,int>,int> memo;
  
public:
  int minDistance(string word1, string word2){
    memo.clear();
    return helperDistance(word1,word1.size()-1,word2,word2.size()-1);
  }

  int helperDistance(const string &word1, int index1, const string &word2, int index2){
    pair<int,int> key = make_pair(index1,index2);

    if(memo.find(key)!=memo.end())
      return memo[key];

    if(index1<0)
      return memo[key] = index2+1;

    if(index2<0)
      return memo[key] = index1+1;

    if(word1[index1]==word2[index2]){
      return memo[key]=helperDistance(word1,index1-1,word2,index2-1);
    }

    memo[key] = (1 + min(helperDistance(word1,index1-1,word2,index2-1),
                      min(helperDistance(word1,index1,word2,index2-1),
                          helperDistance(word1,index1-1,word2,index2))));

    return memo[key];
  }
};

int main(){
  Solution sol;
  cout<<sol.minDistance("intention","execution")<<endl;
  return 0;
}
