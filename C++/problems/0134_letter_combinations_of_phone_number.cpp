// Problem Statement
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int,string> letters = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    vector<string> result;
    
    void recursiveCombination(const string &digits,int index, string curr){
        if(index>=digits.size()){
            result.push_back(curr);
        }
        
        for(auto letter : letters[digits[index]-'0']){
            curr.push_back(letter);
            recursiveCombination(digits,index+1,curr);
            curr.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits.empty()){
            return result;
        }
        string curr;
        recursiveCombination(digits,0,curr);
        return result;
    }
};

void printVec(const vector<string> &vec){
    for(auto val: vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    Solution sol;
    printVec(sol.letterCombinations("23"));
    return 0;
}