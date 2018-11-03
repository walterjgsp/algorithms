// Problem Statement

// Given a balanced parentheses string S, compute the score of the string based on
// the following rule:
//
// - () has score 1
// - AB has score A + B, where A and B are balanced parentheses strings.
// - (A) has score 2 * A, where A is a balanced parentheses string.

// Exemple: () = 1; (())=2; (()(())) = 6

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int scoreOfParentheses(string S) {
    stack<int> val;
    int to_return = 0;

    for(auto par:S){
      if(par=='('){
        val.push(0);
      }else{
        int temp = val.top();
        val.pop();
        if(temp==0)
          temp=1;
        else
          temp*=2;

        if(val.empty())
          to_return+=temp;
        else
          val.top()+=temp;
      }
    }

    return to_return;
  }
};

int main(){
  Solution sol;
  string S = "(()(()))";
  cout<<sol.scoreOfParentheses(S)<<endl;
  return 0;
}
