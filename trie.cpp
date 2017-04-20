#include <bits/stdc++.h>

using namespace std;

//Struct of a trienode
struct Trienode
{
	bool endofWord;
	//If you have a limited number of characters you can change this structure to track the childrens
	//For example: 
	//if your dictionary only holds lowercase characters you can use a vector<bool> childres(26,false)
	map<char,Trienode *> children;

	Trienode(){
		endofWord=false;
	}
};

struct Trie
{
	Trienode *root;

	Trie(){
		root = new Trienode();
	}

	//This function will insert a string in the trie
	void insert(string s){

		//Create a auxiliary variable to walk in the trie
		Trienode *aux = root;

		//Add all the characters until the end of the word is reached
		for(int i=0;i<s.size();i++){

			//Check if the map contain the character, if is true, 
			//is not necessary to add another reference to the character
			//if false, a new node is created and added as children of this node.
			//the auxiliary variable will point to the character and do the process again until the end
			if(aux->children.find(s[i])!=aux->children.end()){
				aux = aux->children.find(s[i])->second;
			}else{
				Trienode *current = new Trienode();
				aux->children.insert(pair<char,Trienode *>(s[i],current));
				aux=current;
			}
		}

		aux->endofWord=true;
	}

	//Search the trie for a determined prefix
	bool prefixSearch(string pref){

		Trienode *aux = root;

		for(int i=0;i<pref.size();i++){

			//Is simple actually, i search in the map for the character
			//if the character not exists in the map then the prefix not exists
			//in the trie;
			if(aux->children.find(pref[i])!=aux->children.end()){
				aux = aux->children.find(pref[i])->second;
			}else
				return false;
		}

		return true;
	}

	//Search the trie for a determined word
	bool wordSearch(string word){

		//Very similar to the prefix search, the difference is
		//that you return exactly the value of the endofWord variable
		//when you reach the final node. Because if its false than 
		//you have the prefix but you don't have the word on the dictionary

		Trienode *aux = root;

		for(int i=0;i<word.size();i++){

			if(aux->children.find(word[i])!=aux->children.end()){
				aux = aux->children.find(word[i])->second;
			}else
				return false;
		}

		return aux->endofWord;
	}

	//Call the recursive function to walk to the trie
	void printWords(){
		string s = "";
		printWord(s,root);
	}

	//Recursive function to walk through the trie and print the words
	void printWord(string s, Trienode* node){
		
		//In a trie, every leaf is a end of a word,
		//so if you reach a leaf then you can print a word.
		if(node ->children.empty()){
			cout<<s<<endl;
		}else{

			//Is possible that a prefix of a bigger word is also a word in the trie.
			//If you reach this case you also need to print the word.
			if(node->endofWord==true)
				cout<<s<<endl;
			//For every children in the node you walk to the leafs.
			for(auto it = node->children.begin();it!=node->children.end();++it){
				printWord(s+it->first,it->second);
			}
		}
	}

	//Function to delete a word from the trie.
	void deleteWord(string word){
	}

	void deleteWord(string word,int index, Trienode *node){
	}
};

int main(){

	Trie t;
	string s;

	while(cin>>s){
		t.insert(s);
	}

	t.printWords();
}