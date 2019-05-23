//Problem Statement
//In a array A of size 2N, there are N+1 unique elements, and exactly one of
//these elements is repeated N times.
/* Return the element repeated N times.
Example :

Input: [1,2,3,3]
Output: 3 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> unique;
        for(auto val : A){
          if(unique.find(val)!=unique.end())
            return val;
          unique.insert(val);
        }
        return 0;
    }
};

int main(){
  vector<int> vec = {1,2,3,3};
  Solution sol;
  cout<<sol.repeatedNTimes(vec)<<endl;
  return 0;
}
