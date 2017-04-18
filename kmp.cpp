#include <bits/stdc++.h>

using namespace std;

//This function is used to create the partial match table
vector<int> createTable(string str){

	vector<int> t_pre(str.size(),0);
	int j=0;

	for(int i=1;i<str.size();i++){
		while(j>0 && str[j]!=str[i])
			j=t_pre[j];
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
	vector<int> match_table;

	cin>>text>>pattern;

	cout<<pattern<<endl;
	match_table = createTable(pattern);
	printVec(match_table);
}