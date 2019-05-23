// Problem Statement
// You have been given a String S consisting of uppercase and lowercase English alphabets.
// You need to change the case of each alphabet in this String. That is, all the
// uppercase letters should be converted to lowercase and all the lowercase letters
// should be converted to uppercase. You need to then print the resultant String to output.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

    char toggle(char c){
        if(c<'a'){
            return c-'A'+'a';
        }
        return c-'a'+'A';
    }
    string stringToggle(string word){

        for(int i=0;i<word.size();i++){
            word[i]=toggle(word[i]);
        }

        return word;
    }
};

int main(){

    Solution sol;
    cout<<sol.stringToggle("abcdE")<<endl;

    return 0;
}
