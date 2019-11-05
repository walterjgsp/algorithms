// Problem Statement
// In a list of songs, the i-th song has a duration of time[i] seconds.
//
// Return the number of pairs of songs for which their total duration in seconds is
// divisible by 60.  Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        unordered_map<int,int> count_remainder;

        for(auto val: time){
            int remainder = val%60;
            if(count_remainder.find((60-remainder)%60)!=count_remainder.end()){
                result+=count_remainder[(60-remainder)%60];
            }
            count_remainder[remainder]++;
        }

        return result;
    }
};

int main(){
  vector<int> time = {30,20,150,100,40};
  Solution sol;

  cout<<sol.numPairsDivisibleBy60(time)<<endl;
  return 0;
}
