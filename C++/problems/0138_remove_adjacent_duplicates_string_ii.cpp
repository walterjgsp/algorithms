// Problem Statement
// Given a string s, a k duplicate removal consists of choosing k adjacent and equal 
// letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made.

// It is guaranteed that the answer is unique.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string pairToString(pair<char,int> p){
        string toReturn(p.second,p.first);
        return toReturn;
    }
public:
    string removeDuplicates(string s, int k) {
        string result;
        deque<pair<int,int>> buffer;

        for(auto c : s){
            if(!buffer.empty() && buffer.back().first == c){
                buffer.back().second++;
            }else{
                buffer.push_back({c,1});
            }

            if(buffer.back().second == k){
                buffer.pop_back();
            }
        }

        while(!buffer.empty()){
            auto curr = buffer.front();
            buffer.pop_front();
            result.append(pairToString(curr));
        }  

        return result;
    }
};

int main(){
    string word = "deeedbbcccbdaa";
    Solution sol;
    cout<<sol.removeDuplicates(word,3)<<endl;
    return 0;
}