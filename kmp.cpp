#include <bits/stdc++.h>

using namespace std;

//This function is used to create the partial match table
//Time Complexity: O(n)
//Space Complexity: O(n)
//n is the size of the str
vector<int> createTable(string str){

	vector<int> t_pre(str.size(),0);
	int j=0;

	for(int i=1;i<str.size();i++){
		while(j>0 && str[j]!=str[i])
			j=t_pre[j-1];
		if(str[j]==str[i])
			j++;
		t_pre[i]=j;
	}

	return t_pre;
}

void printVec(vector<int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main(){

	string text,pattern;
	vector<int> prefix_table,matchs;

	cin>>text>>pattern;

	cout<<text<<endl<<pattern<<endl;
	prefix_table = createTable(pattern);
	printVec(prefix_table);

	int j=0;

	for(int i=0;i<text.size();i++){
		
		while(j>0 && pattern[j]!=text[i])
			j=prefix_table[j-1];

		if(pattern[j]==text[i])
			j++;

		if(j==pattern.size()){
			matchs.push_back(i-j);
			j=0;
		}

	}

	printVec(matchs);
}