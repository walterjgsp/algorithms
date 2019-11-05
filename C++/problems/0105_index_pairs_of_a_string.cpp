// Problem Statement
// Given a text string and words (a list of strings), return all index pairs [i, j] so 
// that the substring text[i]...text[j] is in the list of words.
#include <bits/stdc++.h>

using namespace std;

class Trie{
private:
    struct TNode{
        bool endWord;
        vector<TNode*> children;
        TNode(){
            endWord = false;
            children = vector<TNode*> (26,nullptr);
        }
    };
    
    TNode *root;
    
public:
    Trie(){
        root = new TNode();
    }
    
    void insert(const string &word){
        int index = 0;
        TNode *it = root;
        while(index < word.size()){
            int position = word[index]-'a';
            if(!it->children[position]){
                it->children[position] = new TNode();
            }
            
            it = it->children[position];
            index++;
        }
        
        it->endWord = true;
    }
    
    vector<vector<int>> query(const string &text){
        vector<vector<int>> result;
        TNode *it = nullptr;
        int index = 0,position;
        
        for(int i=0;i<text.size();i++){
            it = root;
            index = i;
            while(it && index < text.size()){
                position = text[index]-'a';
                if(it->endWord){
                    result.push_back({i,index-1});
                }
                it = it->children[position];
                index++;
            }
            if(it && it->endWord){
                result.push_back({i,index-1});
            }
        }
        
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Trie trie;
        for(auto word : words){
            trie.insert(word);
        }
        
        return trie.query(text);
    }
};

void printVec(const vector<vector<int>> &vec){
    for(auto index : vec){
        cout<<"("<<index[0]<<","<<index[1]<<") ";
    }
    cout<<endl;
}

int main(){
    string text = "thestoryofleetcodeandme";
    vector<string> words = {"story","fleet","leetcode"};
    Solution sol;
    printVec(sol.indexPairs(text,words));
    return 0;
}