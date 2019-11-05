// Problem Statement

// International Morse Code defines a standard encoding where each letter is
// mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b"
// maps to "-...", "c" maps to "-.-.", and so on.
//
// For convenience, the full table for the 26 letters of the English alphabet is given below:
//
// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// Now, given a list of words, each word can be written as a concatenation
// of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-",
// (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation,
// the transformation of a word.
//
// Return the number of different transformations among all words we have.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toMorse(const string & word){
      vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....",
        "..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."};
      string to_return;

      for(auto c:word){
        to_return+=morse[c-'a'];
      }

      return to_return;
    }
    int uniqueMorseRepresentations(vector<string>& words) {

        unordered_set<string> unique;
        for(auto word : words){
          unique.insert(toMorse(word));
        }

        return unique.size();
    }
};

int main(){
  vector<string> words = {"gin", "zen", "gig", "msg"};
  Solution sol;
  cout<<sol.uniqueMorseRepresentations(words)<<endl;
  return 0;
}
