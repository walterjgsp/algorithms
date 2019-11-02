//Problem Statement
// Given an undirected graph, return true if and only if it is bipartite.
//
// Recall that a graph is bipartite if we can split it's set of nodes into two
// independent subsets A and B such that every edge in the graph has one node in
// A and another node in B.
//
// The graph is given in the following form: graph[i] is a list of indexes j
// for which the edge between nodes i and j exists.  Each node is an integer
// between 0 and graph.length - 1.  There are no self edges or parallel edges:
// graph[i] does not contain i, and it doesn't contain any element twice.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int,int> colors;

        for(int i=0;i<graph.size();i++){

            if(colors.find(i)==colors.end()){
                int color = 0;

                queue<int> bfs;
                bfs.push(i);

                while(!bfs.empty()){
                    int tam = bfs.size();

                    for(int i=0;i<tam;i++){
                        int vertex = bfs.front();
                        bfs.pop();

                        if(colors.find(vertex)!=colors.end())
                            continue;

                        colors[vertex] = color;

                        for(int edge : graph[vertex]){
                            if(colors.find(edge)!=colors.end()){
                                if(colors[edge]==color)
                                    return false;
                            }else{
                                bfs.push(edge);
                            }
                        }
                    }

                    color = color ^ 1;
                }
            }
        }

        return true;
    }
};

int main(){
  vector<vector<int>> graph = {{1,3}, {0,2}, {1,3}, {0,2}};
  Solution sol;

  cout<<sol.isBipartite(graph)<<endl;

  return 0;
}
