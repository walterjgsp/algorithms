//Problem Statement
//We're going to make our own Contacts application! The application must perform two types of operations:

//add name, where  is a string denoting a contact name. 
//  This must store  as a new contact in the application.
//find partial, where  is a string denoting a partial name to search the 
//  application for. It must count the number of contacts starting with  and print the count on a new line.
//Given  sequential add and find operations, perform each operation in order.
#include <bits/stdc++.h>

using namespace std;

class Trie{
private:
    struct TNode{
        bool endWord;
        int count;
        vector<TNode*> childs;
        TNode(){
            count = 0;
            endWord = false;
            childs = vector<TNode*>(26,nullptr);
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
        while(index<word.size()){
            int position = word[index]-'a';
            if(!it->childs[position]){
                it->childs[position] = new TNode();
            }

            it = it->childs[position];
            it->count++;
            index++;
        }

        it->endWord = true;
    }

    int queryPrefixCount(const string &prefix){
        int index = 0;
        TNode *it = root;
        while(index<prefix.size()){
          int position = prefix[index] - 'a';
          if (!it->childs[position]) {
            return 0;
            }

            it = it->childs[position];
            index++;
        }

        return it->count;
    }
};

class Solution{
public:
    vector<int> contacts(vector<vector<string>> queries) {
        vector<int> result;
        Trie trie;
        for(auto query : queries){
            if(query[0]=="add"){
                trie.insert(query[1]);
            }else{
                result.push_back(trie.queryPrefixCount(query[1]));
            }
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
    Solution sol;
    vector<vector<string>> queries = {{"add","hack"},{"add","hackerrank"},{"find","hac"},{"find","hak"}};
    printVec(sol.contacts(queries));

    return 0;
}
