#include <bits/stdc++.h>

using namespace std;

class Trie{
private:
	class TrieNode{
	public:
		vector<TrieNode*> childs;
		bool endWord;
		TrieNode(){
			childs = vector<TrieNode*> (26,0);
			endWord = false;
		}
	};

	TrieNode *root;
public:
	Trie(){
		root = new TrieNode();
	}

	void insert(const string &word){
		int index = 0;
		TrieNode* it = root;

		while(index<word.size()){
			int pos = word[index]-'a';
			if(!it->childs[pos])
				it->childs[pos] = new TrieNode();

			it = it->childs[pos];
			index++;
		}

		it->endWord = true;
	}

	bool query(const string &word){
		int index = 0;
		TrieNode *it = root;

		while(index<word.size()){
			int pos = word[index]-'a';
			if(!it->childs[pos])
				return false;
			it = it->childs[pos];
			index++;
		}

		return it->endWord;
	}

	void printWords(){
			string temp;
			TrieNode *it = root;
			for(int i=0;i<it->childs.size();i++){
				if(it->childs[i]){
					temp.push_back(i+'a');
					printWord(temp,it->childs[i]);
					temp.pop_back();
				}
			}
	}

	void printWord(string word,TrieNode *node){
		if(node->endWord)
			cout<<word<<endl;

		for(int i=0;i<node->childs.size();i++){
			if(node->childs[i]){
				word.push_back(i+'a');
				printWord(word,node->childs[i]);
				word.pop_back();
			}
		}
	}

};

int main(){

	Trie t;
	t.insert("abacate");
	t.insert("aba");
	t.insert("panela");
	t.printWords();
	if(t.query("aba"))
		cout<<"Found"<<endl;
}
