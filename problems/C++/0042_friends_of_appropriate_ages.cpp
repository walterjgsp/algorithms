//Problem Statement
// Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.
//
// Person A will NOT friend request person B (B != A) if any of the following conditions are true:
//
// age[B] <= 0.5 * age[A] + 7
// age[B] > age[A]
// age[B] > 100 && age[A] < 100
// Otherwise, A will friend request B.
//
// Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
//
// How many total friend requests are made?

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> counter(121,0);
        int result = 0;

        for(auto age:ages){
            counter[age]++;
        }

        for(int i=1;i<counter.size();i++){
            counter[i+1]+=counter[i];
        }

        for(auto age:ages){
            result += max(0,counter[age]-counter[age/2+7]-1);
        }

        return result;
    }
};

int main(){
  vector<int> ages = {20,30,100,110,120};
  Solution sol;
  cout<<sol.numFriendRequests(ages)<<endl;
  return 0;
}
