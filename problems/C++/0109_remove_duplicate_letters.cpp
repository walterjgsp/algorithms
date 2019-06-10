// Problem Statement
// Given a string which contains only lowercase letters, remove duplicate letters 
// so that every letter appear once and only once. You must make sure your result 
// is the smallest in lexicographical order among all possible results.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    string removeDuplicateLetters(string text){
        string result;
        if(text.empty())
            return result;

        vector<int> count(26,0);
        for(auto c: text){
            count[c-'a']++;
        }

        vector<bool> used(26,false);
        for(auto c: text){
            count[c-'a']--;
            if(used[c-'a'])
                continue;
            
            while(!result.empty() && c<result.back() && count[result.back()]>0){
                used[result.back()-'a']=false;
                result.pop_back();
            }

            result+=c;
            used[c-'a'] = true;
        }

        return result;
    }
};

int main(){
    string text = "cbacdcbc";
    Solution sol;
    cout<<sol.removeDuplicateLetters(text)<<endl;
    return 0;
}