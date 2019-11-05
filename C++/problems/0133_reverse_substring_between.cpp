// Problem Statement
// Given a string s that consists of lower case English letters and brackets. 

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any bracket.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> indexes;
        string result;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                indexes.push(i);
            }else if(s[i]==')'){
                int curr = indexes.top();
                indexes.pop();
                reverse(s.begin()+curr,s.begin()+i);
            }
        }
        
        for(auto c : s){
            if(c==')' || c=='(')
                continue;
            result.push_back(c);
        }
        
        return result;
    }
};

int main(){
    string word = "(ed(et(oc))el)";
    Solution sol;
    cout<<sol.reverseParentheses(word)<<endl;
    return 0;
}