// Problem Statement
// Given a positive integer n and you can do operations as follow:
//
// If n is even, replace n with n/2.
// If n is odd, you can replace n with either n + 1 or n - 1.
// What is the minimum number of replacements needed for n to become 1?
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int,int> memo;
public:
    int integerReplacement(int n) {

        if(n==INT_MAX)
            return 32;

        if(memo.count(n)>0)
            return memo[n];

        if(n==1)
            return memo[n]=0;

        if(n%2==0)
            return memo[n]=(1+integerReplacement(n/2));
        else{
            int min_replacement = min(integerReplacement(n+1),integerReplacement(n-1));
            memo[n]=min_replacement+1;
            return memo[n];
        }
    }
};

int main(){
  Solution sol;
  cout<<sol.integerReplacement(7)<<endl;
  return 0;
}
