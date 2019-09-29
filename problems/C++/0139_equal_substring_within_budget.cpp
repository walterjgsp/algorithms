// Problem Statement
// You are given two strings s and t of the same length. You want to change s to t. 
// Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, 
// the absolute difference between the ASCII values of the characters.

// You are also given an integer maxCost.

// Return the maximum length of a substring of s that can be changed to be the same as the 
// corresponding substring of twith a cost less than or equal to maxCost.

// If there is no substring from s that can be changed to its corresponding substring from t, return 0.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs(s.size(),0);
        
        for(int i=0;i<s.size();i++){
            costs[i] = abs(s[i]-t[i]);
        }
        
        int result = 0,curr_cost = 0,start=0;
        
        for(int i=0;i<costs.size();i++){
            curr_cost+=costs[i];
            while(start<=i && curr_cost>maxCost){
                curr_cost-=costs[start];
                start++;
            }
            
            if(start == i && costs[start]<=maxCost){
                result = max(result,1);
            }else if(curr_cost<=maxCost){
                result = max(result,i-start+1);                
            }
        }
        
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.equalSubstring("abcd","bcdf",3)<<endl;
    return 0;
}