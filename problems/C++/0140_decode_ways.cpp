// Problem Statement
// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int helperDecoding(string s, int right_start,vector<int> &memo){
        if(memo[right_start]!=INT_MIN){
            return memo[right_start];
        }
        
        if(right_start==s.size()){
            return memo[right_start]=1;
        }
        
        if(s[right_start]=='0'){
            return memo[right_start]=0;
        }
        
        int result = helperDecoding(s,right_start+1,memo);
        if(right_start<s.size()-1){
            int two_letters = 10*(s[right_start]-'0')+(s[right_start+1]-'0');
            if(two_letters>=10 && two_letters<=26){
                result+=helperDecoding(s,right_start+2,memo);
            }
        }
        
        return memo[right_start]=result;
    }
public:
    int numDecodings(string s) {
        vector<int> memo(s.size()+1,INT_MIN);
        return helperDecoding(s,0,memo);
    }
};

int main(){
    Solution sol;
    cout<<sol.numDecodings("1234")<<endl;
    return 0;
}