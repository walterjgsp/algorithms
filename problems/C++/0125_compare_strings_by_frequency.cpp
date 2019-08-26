// Problem Statement
// Let's define a function f(s) over a non-empty string s, which calculates the frequency 
// of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the
// smallest character is "c" and its frequency is 2.

// Now, given string arrays queries and words, return an integer array answer, 
// where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int f(const string &word){
        vector<int> count(26,0);
        for(auto c : word){
            count[c-'a']++;
        }

        for(auto val : count){
            if(val>0){
                return val;
            }
        }

        return -1;
    }

    int searchSmaller(const vector<pair<int,int>> &prefix_sum, const int & f_value){
        int start = 0, end = prefix_sum.size()-1;

        while(start<=end){
            int mid = start + (end-start)/2;

            if(prefix_sum[mid].first <= f_value){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        if(end<0) return 0;
        return (prefix_sum[end].first > f_value) ? prefix_sum[end].second : 0;
    }

public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        map<int,int> memo;
        vector<int> result;
        for(auto word : words){
            int f_val = f(word);
            memo[f_val]++;
        }

        vector<pair<int,int>> prefix_sum;
        for(auto it = memo.rbegin();it!=memo.rend();it++){
            pair<int,int> new_reg = make_pair(it->first,it->second);
            if(!prefix_sum.empty()){
                new_reg.second += prefix_sum.back().second;
            }
            prefix_sum.push_back(new_reg);
        }

        for(auto query : queries){
            int f_val = f(query);
            result.push_back(searchSmaller(prefix_sum,f_val));
        }

        return result;
    }
};

void printVec(const vector<int> &vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<string> words = {"a","aa","aaa","aaaa","bbbc"}, queries = {"bbb","cc","c","aaaa"};
    Solution sol;
    printVec(sol.numSmallerByFrequency(queries,words));
    return 0;
}