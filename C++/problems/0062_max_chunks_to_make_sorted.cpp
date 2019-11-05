//Problem Statement
// Given an array arr that is a permutation of [0, 1, ..., arr.length - 1],
// we split the array into some number of "chunks" (partitions), and individually
// sort each chunk.  After concatenating them, the result equals the sorted array.
//
// What is the most number of chunks we could have made?
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> sorted;
        int result = 0;
        
        for(int pos=0;pos<arr.size();pos++){
            sorted.push(arr[pos]);

            while(!sorted.empty() && sorted.top()<=pos){
                sorted.pop();
            }

            if(sorted.empty())
                result++;
        }

        return result;
    }
};

int main(){
  vector<int> arr = {1,0,2,3,4};
  Solution sol;
  cout<<sol.maxChunksToSorted(arr)<<endl;
  return 0;
}
