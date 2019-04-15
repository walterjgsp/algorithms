// Problem Statement
// There are N network nodes, labelled 1 to N.
//
// Given times, a list of travel times as directed edges times[i] = (u, v, w),
// where u is the source node, v is the target node, and w is the time it takes
// for a signal to travel from source to target.
//
// Now, we send a signal from a certain node K. How long will it take for all
// nodes to receive the signal? If it is impossible, return -1.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      vector<vector<pair<int,int>>> graph (N);
      vector<int> djkistra(N,INT_MAX);

      for(auto edge : times){
        graph[edge[0]-1].push_back({edge[1]-1,edge[2]});
      }

      int start = K-1;
      unordered_set<int> visited;
      priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

      djkistra[start]=0;
      pq.push({0,start});

      while(!pq.empty()){
        auto actual = pq.top();
        pq.pop();

        if(visited.find(actual.second)==visited.end()){
          visited.insert(actual.second);

          for(auto edge : graph[actual.second]){
            djkistra[edge.first] = min(djkistra[edge.first],djkistra[actual.second]+edge.second);
            pq.push({djkistra[edge.first],edge.first});
          }
        }
      }

      int result = INT_MIN;
      for(auto val : djkistra){
        if(val==INT_MAX)
          return -1;
        result = max(result,val);
      }

      return result;
    }
};

int main(){
  vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
  int N = 4, K=2;
  Solution sol;
  cout<<sol.networkDelayTime(times,N,K)<<endl;

  return 0;
}
