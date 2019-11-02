// Problem Statement
// Given two strings S and T, determine if they are both one edit distance apart.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s1, string s2) {
        int i=0,j=0, diff_count = 0;
        
        int diff = s1.size()-s2.size();
        if(abs(diff)>1) 
        return false;
        
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
                
                if(diff_count>1){
                    return false;
                }

                if(s2.size() == s1.size()){
                    i++,j++;
                }else if(s2.size() < s1.size()){
                    i++;
                }else{
                    j++;
                }

                diff_count++;
            }else{
                i++,j++;
            }

            
        }

        if (i < s1.size() || j < s2.size()) 
            diff_count++; 
    
        return diff_count == 1; 
    }
};

int main(){
    string s1 = "geeks", s2="geek";
    Solution sol;
    cout<<sol.isOneEditDistance(s1,s2)<<endl;
    return 0;
}