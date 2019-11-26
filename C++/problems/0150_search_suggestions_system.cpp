// Problem Statement
// Given an array of strings products and a string searchWord. We want to design a system that 
// suggests at most three product names from products after each character of searchWord is typed. 
// Suggested products should have common prefix with the searchWord. If there are more than three 
// products with a common prefix return the three lexicographically minimums products.

// Return list of lists of the suggested products after each character of searchWord is typed. 
#include "0150_search_suggestions_system.hpp"
#include <bits/stdc++.h>

using namespace std;

class Trie{
private:
    struct TNode{
        bool endWord;
        vector<TNode*> children;
        TNode(){
            endWord = false;
            children = vector<TNode*>(26,nullptr);
        }
    };
    
    TNode *root;
    
    void getWordsFrom(TNode *node,string word,vector<string> &words){
        if(!node || words.size()>=3){
            return;
        }
        
        if(node->endWord){
            words.push_back(word);
        }
        
        for(int i=0;i<26;i++){
            if(node->children[i]){
                word.push_back(('a'+i));
                getWordsFrom(node->children[i],word,words);
                word.pop_back();
            }
        }
    }

public:
    Trie(){
        root = new TNode();
    }
    
    void insert(const string &word){
        TNode *it = root;
        int index = 0;
        while(index<word.size()){
            int pos = word[index]-'a';
            if(!it->children[pos]){
                it->children[pos] = new TNode();
            }
            
            it = it->children[pos];
            index++;
        }
        
        it->endWord = true;
    }
    
    vector<string> query(string &word){
        vector<string> result;
        TNode *it = root;
        int index = 0;
        while(index<word.size()){
            int pos = word[index]-'a';
            if(!it->children[pos]){
                return result;
            }
            
            it = it->children[pos];
            index++;
        }
        
        getWordsFrom(it,word,result);
        
        return result;
    }
};

vector<vector<string>> Solution::suggestedProducts(vector<string>& products, string searchWord){
    vector<vector<string>> result;
    Trie trie;
    
    for(auto product : products){
        trie.insert(product);
    }
    
    string query;
    for(auto c: searchWord){
        query.push_back(c);
        result.push_back(trie.query(query));
    }
    
    return result;
}