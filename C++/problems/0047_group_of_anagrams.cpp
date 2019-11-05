/* Problem Statement

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
] */

class Solution {
public:
    vector<int> getVec(const string &word){
        vector<int> counter (26,0);

        for(auto letter : word){
            counter[letter-'a']++;
        }

        return counter;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>,vector<string>> groups;
        vector<vector<string>> result;

        for(auto word:strs){
            groups[getVec(word)].push_back(word);
        }

        for(auto group:groups){
            result.push_back(group.second);
        }

        return result;
    }
};

void printVec(const vector<int> &vec){
  for(auto val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution sol;
  vector<vector<string>> groups = sol.groupAnagrams(strs);

  for(auto group : groups){
    printVec(group);
  }

  return 0;
}
