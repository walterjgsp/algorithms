//This function is used to create the partial match table
//Time Complexity: O(n)
//Space Complexity: O(n)
//n is the size of the str

#include <bits/stdc++.h>

using namespace std;

vector<int> createTable(string str){
	//Create a vector the size of the pattern you are looking for
	vector<int> t_pre(str.size(),0);
	int j=0;

	//That is the trick part, you will walk through all the pattern
	for(int i=1;i<str.size();i++){
		//Your j will increment only if you find a match inside the pattern, this means
		//only if the value of str[i] == str[j]. The secret of this algorithm is that you don't
		//need to return the value of j one by one, in reality you can't do that. Since you already
		//keep a track of the matching prefixes, you return to the start of the last matching prefix.
		//Then you compare the value of str[i] with the start of this matching prefix.
		//This happens until the j returns to the beginning of the pattern.
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
		//What you do here is very similar to the creation of the preffix table
		//You know the start of the preffixes that are similar. With this you can keep a track
		//of how many positions of the pattern you can ignore because you have already compared.
		//If you cant ignore none you return j to the start of the pattern and let the value of i increment.
		while(j>0 && pattern[j]!=text[i])
			j=prefix_table[j-1];

		if(pattern[j]==text[i])
			j++;

		//If the value of j is equal to the pattern size you found a full match of the pattern in the text.
		//This kmp was implemented to find all the patterns match inside the text.
		if(j==pattern.size()){
			matchs.push_back(i-j);
			j=0;
		}
	}

	printVec(matchs);
}
