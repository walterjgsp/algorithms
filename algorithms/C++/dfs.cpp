//Depth-first search (DFS) is an algorithm for traversing or
//searching tree or graph data structures.
//Time Complexity: O(V+E)
//Space Complexity: O(V+E)
#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
  vector<vector<int>> adjList;

public:
  Graph(){}

  Graph(int vertexes){
    adjList = vector<vector<int>> (vertexes);
  }

  void addEdge(int start, int end){
    adjList[start].push_back(end);
  }

  vector<int> getNeighbors(const int &vertex){
    return adjList[vertex];
  }

  void printGraph(){
    for(int i=0;i<adjList.size();i++){
      cout<<i<<": ";
      for(int j=0;j<adjList[i].size();j++){
        cout<<adjList[i][j]<<"->";
      }
      cout<<"NULL"<<endl;
    }
  }
};

void printVec(const vector<int> &vec){
  for(auto val : vec){
    cout<<val<<" ";
  }
  cout<<endl;
}

class DFS{
private:
  Graph graph;
public:
  DFS(Graph g){
    graph = g;
  }

  vector<int> dfsFrom(const int &src){
    stack<int> helper;
    unordered_set<int> visited;
    vector<int> to_return;

    helper.push(src);

    while(!helper.empty()){
      int actual_vertex = helper.top();

      if(visited.find(actual_vertex)!=visited.end()){
        helper.pop();
        to_return.push_back(actual_vertex);
      }else{
        vector<int> neighbors = graph.getNeighbors(actual_vertex);
        for(auto neighbor : neighbors)
          helper.push_back(neighbor);
      }
    }

    return to_return;
  }
}

int main(){
  Graph graph(4);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(2, 3);
  graph.addEdge(3, 3);

  graph.printGraph();

  DFS dfs(graph);
  printVec(dfs.dfsFrom(1));

  return 0;
}
