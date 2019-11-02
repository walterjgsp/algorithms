//Kruskal is an algorithm used to find the minimum-spanning-tree
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

class Kruskal{
private:
  vector<int> parents;

public:
  int find(int x){
    if(parents[x]==x)
      return parents[x];
    return find(parents[x]);
  }

  void Union(int x, int y){
    int xparent = find(x);
    int yparent = find(y);

    if(xparent!=yparent)
      parents[x] = parents[y];
  }

  Graph applyKruskal(Graph &graph){
    //Prepare for union find algorithm to detect cycles;
    parents.clear();
    parents.resize(graph.getSize());
    for(int i=0;i<parents.size();i++){
      parents[i]=i;
    }

    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > helper;
    auto adjList = graph.getGraphAdjList();

    for(int vertex=0;vertex<adjList.size();vertex++){
      auto edges = adjList[vertex];
      for(auto edge : edges){
        helper.push({edge.second,{vertex,edge.first}});
      }
    }

    vector<pair<int,pair<int,int>>> edgesToGraph;

    while (!helper.empty()) {
      auto current = helper.top();
      helper.pop();

      int xparent = find(current.second.first);
      int yparent = find(current.second.second);

      if(xparent!=yparent){
        edgesToGraph.push_back(current);
        Union(xparent,yparent);
      }
    }

    Graph spanningTree(graph.getSize());

    for(auto edge : edgesToGraph){
      spanningTree.addEdge(edge.second.first,edge.second.second,edge.first);
    }

    return spanningTree;
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

  Kruskal kruskal;
  cout<<"Spanning Tree:"<<endl;
  Graph spanningTree = kruskal.applyKruskal(graph);
  spanningTree.printGraph();

  return 0;
}
