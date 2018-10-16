// Problem Statement

// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

#include <bits/stdc++.h>

using namespace std;

string toLowerCase(string str) {

    string to_return;

    for(auto c:str){
        if(c>='A' && c<='Z')
            c='a'+c-'A';

        to_return.push_back(c);
    }

    return to_return;
}

int main(){
  string str = "CODETOLOWER";
  cout<<toLowerCase(str)<<endl;
  return 0;
}
