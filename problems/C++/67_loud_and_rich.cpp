//Problem Statement
// In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different
// amounts of money, and different levels of quietness.
//
// For convenience, we'll call the person with label x, simply "person x".
//
// We'll say that richer[i] = [x, y] if person x definitely has more money than person y.
// Note that richer may only be a subset of valid observations.
//
// Also, we'll say quiet[x] = q if person x has quietness q.
//
// Now, return answer, where answer[x] = y if y is the least quiet person
// (that is, the person y with the smallest value of quiet[y]), among all
// people who definitely have equal to or more money than person x.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<int,int> memo;
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        memo.clear();
        vector<vector<int>> graph(quiet.size());

        for(auto rich : richer){
            graph[rich[1]].push_back(rich[0]);
        }

        vector<int> result (quiet.size());

        for(int i=0;i<result.size();i++){
            result[i]=helper(graph,quiet,i);
        }

        return result;
    }

    int helper(const vector<vector<int>> &graph, const vector<int> &quiet, int index){
        if(memo.find(index)!=memo.end())
            return memo[index];

        if(graph[index].empty())
            return memo[index]=index;

        int quieter = index;
        for(auto val : graph[index]){
            int actual = helper(graph,quiet,val);
            if(quiet[quieter]>quiet[actual]){
                quieter = actual;
            }
        }

        return memo[index] = quieter;
    }
};

void printVec(vector<int> arr){
  for(auto val : arr)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
  vector<int> quiet = {3,2,5,4,6,1,7,0};
  Solution sol;

  printVec(sol.loudAndRich(richer,quiet));

  return 0;
}
