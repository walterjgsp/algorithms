//Prim is an algorithm used to find the minimum-spanning-tree
//from a graph
//Time Complexity: O(E log V)
//Space Complexity: O(V+E)
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> triple_t;

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
    priority_queue<triple_t,vector<triple_t>, greater<triple_t>> pq;
    vector<triple_t> edgesToGraph;
    int currWeight,currInit,currEnd;

    for(auto edge : graph.getNeighbors(0)){
      pq.push(make_tuple(edge.second,0,edge.first));
    }
    included_vertexes.insert(0);

    while(!pq.empty() && included_vertexes.size()<graph.getSize()){
      tie(currWeight,currInit,currEnd) = pq.top();
      pq.pop();

      if(included_vertexes.find(currEnd)==included_vertexes.end()){
        included_vertexes.insert(currEnd);

        edgesToGraph.push_back(make_tuple(currInit,currEnd,currWeight));
        for(auto edge : graph.getNeighbors(currEnd)){
          if(included_vertexes.find(edge.first)==included_vertexes.end()){
            pq.push(make_tuple(edge.second,currEnd,edge.first));
          }
        }
      }
    }

    Graph minST = Graph(graph.getSize());
    for(auto it : edgesToGraph){
      tie(currInit,currEnd,currWeight) = it;
      minST.addEdge(currInit,currEnd,currWeight);
    }


    return minST;
  }
};

int main(){
  // Graph graph(7);

  // graph.addEdge(0,3,5);
  // graph.addEdge(0,1,7);
  // graph.addEdge(1,2,8);
  // graph.addEdge(1,3,9);
  // graph.addEdge(1,4,7);
  // graph.addEdge(2,4,5);
  // graph.addEdge(3,4,15);
  // graph.addEdge(3,5,6);
  // graph.addEdge(4,5,8);
  // graph.addEdge(4,6,9);
  // graph.addEdge(5,6,11);
  Graph graph(4);
  graph.addEdge(0,1,1);
  graph.addEdge(2,1,150);
  graph.addEdge(3,2,99);
  graph.addEdge(0,3,100);
  graph.addEdge(2,0,200);

  graph.printGraph();

  Prim prim;
  cout<<"Spanning Tree:"<<endl;
  Graph spanningTree = prim.applyPrim(graph);
  spanningTree.printGraph();

  return 0;
}
