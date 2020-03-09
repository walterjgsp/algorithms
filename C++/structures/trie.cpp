#include <bits/stdc++.h>

using namespace std;

class Trie{
private:
	class TNode{
	public:
		vector<TNode*> children;
		bool endWord;
		TNode(){
			children = vector<TNode*> (26,NULL);
			endWord = false;
		}
	};

	TNode *root;

public:
	Trie(){
		root = new TNode();
	}

	void insert(const string &word){
		int index = 0;
		TNode* it = root;

		while(index<word.size()){
			int pos = word[index]-'a';
			if(!it->children[pos])
				it->children[pos] = new TNode();

			it = it->children[pos];
			index++;
		}

		it->endWord = true;
	}

	bool query(const string &word){
		int index = 0;
		TNode *it = root;

		while(index<word.size()){
			int pos = word[index]-'a';
			if(!it->children[pos])
				return false;
			it = it->children[pos];
			index++;
		}

		return it->endWord;
	}

	void printWords(){
			string temp;
			TNode *it = root;
			for(int i=0;i<it->children.size();i++){
				if(it->children[i]){
					temp.push_back(i+'a');
					printWord(temp,it->children[i]);
					temp.pop_back();
				}
			}
	}

	void printWord(string word,TNode *node){
		if(node->endWord)
			cout<<word<<endl;

		for(int i=0;i<node->children.size();i++){
			if(node->children[i]){
				word.push_back(i+'a');
				printWord(word,node->children[i]);
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
