//Problem Statement
// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
//
// Each person may dislike some other people, and they should not go into the same group.
//
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
//
// Return true if and only if it is possible to split everyone into two groups in this way.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        vector<int> colors(N+1,-1);
        unordered_set<int> visited;

        for(auto dis : dislikes){
            graph[dis[0]].push_back(dis[1]);
            graph[dis[1]].push_back(dis[0]);
        }

        for(int src=1;src<graph.size();src++){
            if(visited.find(src)==visited.end()){
                queue<int> bfs;
                bfs.push(src);
                colors[src]=0;

                while(!bfs.empty()){
                    int actual = bfs.front();
                    bfs.pop();

                    visited.insert(actual);
                    vector<int> neigh = graph[actual];

                    for(auto n:neigh){
                        if(colors[n]==colors[actual])
                            return false;
                        colors[n]=colors[actual] ^ 1;
                        if(visited.find(n)==visited.end())
                            bfs.push(n);
                    }
                }
            }
        }

        return true;
    }
};

int main(){
  vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
  int n = 3;
  Solution sol;
  cout<< sol.possibleBipartition(n,edges)<<endl;
  return 0;
}
