//Problem Statement
// Given an array A of strings made only from lowercase letters, return a list of all
// characters that show up in all strings within the list (including duplicates).
// For example, if a character occurs 3 times in all strings but not 4 times,
// you need to include that character three times in the final answer.
//
// You may return the answer in any order.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countLetters(string word){
        vector<int> counter(26,0);
        for(auto c: word){
            counter[c-'a']++;
        }
        return counter;
    }

    void mergeCounter(vector<int> &c1,const vector<int> &c2){
        for(int i=0;i<c1.size();i++){
            c1[i] = min(c1[i],c2[i]);
        }
    }

    vector<string> commonChars(vector<string>& A) {
        vector<int> counter = countLetters(A[0]);
        vector<string> result;

        for(int i=1;i<A.size();i++){
            mergeCounter(counter,countLetters(A[i]));
        }

        for(int i=0;i<counter.size();i++){
            while(counter[i]>0){
                string temp(1,('a'+i));
                result.push_back(temp);
                counter[i]--;
            }
        }

        return result;
    }
};

void printVec(const vector<string> &arr){
  for(auto s : arr){
    cout<<s<<" ";
  }
  cout<<endl;
}

int main(){
  vector<string> arr = {"bella","label","roller"};
  Solution sol;
  printVec(sol.commonChars(arr));
  return 0;
}
