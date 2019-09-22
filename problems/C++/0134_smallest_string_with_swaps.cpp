// Problem Statement
// You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] 
// indicates 2 indices(0-indexed) of the string.

// You can swap the characters at any pair of indices in the given pairs any number of times.

// Return the lexicographically smallest string that s can be changed to after using the swaps.
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int,int>> parents;
    
    int find(int x){
        if(x!=parents[x].first){
            parents[x].first = find(parents[x].first);
        }
        return parents[x].first;
    }
    
    void Union(int x, int y){
        int parentx = find(x);
        int parenty = find(y);
        
        if(parentx!=parenty){
            if(parents[parentx].second>parents[parenty].second){
                parents[parenty].first = parentx;
            }else if(parents[parentx].second<parents[parenty].second){
                parents[parentx].first = parenty;
            }else{
                parents[parenty].first = parentx;
                parents[parentx].second++;
            }
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parents = vector<pair<int,int>>(s.size());
        vector<int> group(s.size());
        map<int,vector<char>> memo;
        string result;
        
        for(int i=0;i<parents.size();i++){
            parents[i] = {i,0};
        }
        
        for(auto p : pairs){
            Union(p[0],p[1]);
        }
        
        for(int i=0;i<s.size();i++){
            int parenti = find(i);
            group[i]=parenti;
            memo[parenti].push_back(s[i]);
        }
        
        for(auto it : memo){
            auto vec = it.second;
            sort(vec.begin(),vec.end(),greater<char>());
            memo[it.first] = vec;
        }
        
        for(int i=0;i<group.size();i++){
            result+=memo[group[i]].back();
            memo[group[i]].pop_back();
        }
        
        return result;
    }
};

int main(){
    string word = "dcab";
    vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
    Solution sol;
    cout<<sol.smallestStringWithSwaps(word,pairs);

    return 0;
}