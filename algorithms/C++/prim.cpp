//Prim is an algorithm used to find the minimum-spanning-tree
//from a graph
//Time Complexity: O(E log V)
//Space Complexity: O(V+E)
#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
  vector<vector<pair<int,int>>> adjList;

public:
  Graph(int graph_size){
    adjList.clear();
    adjList.resize(graph_size);
  }

  void addEdge(int from, int to, int weight){
    adjList[from].push_back({to,weight});
    adjList[to].push_back({from,weight});
  }

  vector<pair<int,int>> getNeighbors(int vertex){
    return adjList[vertex];
  }

  vector<vector<pair<int,int>>> getGraphAdjList(){
    return adjList;
  }

  int getSize(){
    return adjList.size();
  }

  void printGraph(){
    for(int i=0;i<adjList.size();i++){
      cout<<i<<": ";
      for(int j=0;j<adjList[i].size();j++){
        cout<<"("<<adjList[i][j].first<<","<<adjList[i][j].second<<") -> ";
      }
      cout<<"NULL"<<endl;
    }
  }
};

class Prim{
private:
  set<int> included_vertexes;

public:
  Graph applyPrim(Graph &graph){
    included_vertexes.clear();
    priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
    vector<pair<int,pair<int,int>>> edgesToGraph;
    included_vertexes.insert(0);
    auto adjList = graph.getGraphAdjList();

    for(auto edges : adjList[0]){
      pq.push({edges.second,{0,edges.first}});
    }

    while(!pq.empty() && included_vertexes.size()<graph.getSize()){
      auto current = pq.top();
      pq.pop();

      if(included_vertexes.find(current.second.first)==included_vertexes.end() ||
         included_vertexes.find(current.second.second)==included_vertexes.end()){

           edgesToGraph.push_back({current.second.first,{current.second.second,current.first}});

           for(auto edges : adjList[current.second.second]){
             if(included_vertexes.find(edges.first)==included_vertexes.end())
              pq.push({edges.second,{current.second.second,edges.first}});
           }

           included_vertexes.insert(current.second.first);
           included_vertexes.insert(current.second.second);
         }
    }

    Graph minSPT(graph.getSize());
    for(auto edge : edgesToGraph){
      minSPT.addEdge(edge.first,edge.second.first,edge.second.second);
    }

    return minSPT;
  }
};

int main(){
  Graph graph(7);

  graph.addEdge(0,3,5);
  graph.addEdge(0,1,7);
  graph.addEdge(1,2,8);
  graph.addEdge(1,3,9);
  graph.addEdge(1,4,7);
  graph.addEdge(2,4,5);
  graph.addEdge(3,4,15);
  graph.addEdge(3,5,6);
  graph.addEdge(4,5,8);
  graph.addEdge(4,6,9);
  graph.addEdge(5,6,11);
  graph.printGraph();

  Prim prim;
  cout<<"Spanning Tree:"<<endl;
  Graph spanningTree = prim.applyPrim(graph);
  spanningTree.printGraph();

  return 0;
}
