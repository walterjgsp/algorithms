//Problem Statement
// Lilah has a string, s , of lowercase English letters that she repeated infinitely many times.
//
// Given an integer, n , find and print the number of letter a's in the first n letters of Lilah's infinite string.
//
// For example, if the string s='abcac' and n=10, the substring we consider is 'abcacabcac',
// the first 10 characters of her infinite string. There are 4 occurrences of a in the substring.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
  long repeatedString(string s, long n) {
    long remainder = n%s.size(),full = n/s.size();
    long count_remainder = 0,count_full = 0;

    for(int i =0;i<s.size();i++){
        if(s[i]=='a'){
            if(i<remainder)
                count_remainder++;
            count_full++;
        }
    }

    return count_remainder+count_full*full;
  }
};

int main(){
  Solution sol;
  string s = "abcac";
  cout<<sol.repeatedString(s,10)<<endl;
  return 0;
}
