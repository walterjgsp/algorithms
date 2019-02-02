//Problem Statement
// In a directed graph, we start at some node and every turn, walk along a directed
// edge of the graph.  If we reach a node that is terminal
// (that is, it has no outgoing directed edges), we stop.
//
// Now, say our starting node is eventually safe if and only if we must eventually
// walk to a terminal node.  More specifically, there exists a natural number K so
// that for any choice of where to walk, we must have stopped at a terminal node in
// less than K steps.
//
// Which nodes are eventually safe?  Return them as an array in sorted order.
//
// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length
// of graph.  The graph is given in the following form: graph[i] is a list of labels
// j such that (i, j) is a directed edge of the graph.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int,bool> node_state;
        vector<int> result;

        for(int i=0;i<graph.size();i++){

            if(node_state.find(i)==node_state.end()){
                unordered_set<int> visited;
                dfs(graph,i,node_state,visited);
            }

            if(node_state[i])
                result.push_back(i);
        }

        return result;
    }

    bool dfs(const vector<vector<int>> &graph, int vertex,
             map<int,bool> &node_state,unordered_set<int> visited){

        if(node_state.find(vertex)!=node_state.end())
            return node_state[vertex];

        if(visited.find(vertex)!=visited.end())
            return node_state[vertex]=false;

        visited.insert(vertex);

        bool isSafe = true;
        for(auto neighbors : graph[vertex]){
            isSafe = isSafe && dfs(graph,neighbors,node_state,visited);
        }

        return node_state[vertex]=isSafe;
    }
};

void printVec(vector<int> vec){
  for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
}

int main(){
  vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
  Solution sol;
  printVec(sol.eventualSafeNodes(graph));
  return 0;
}
