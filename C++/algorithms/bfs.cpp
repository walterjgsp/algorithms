//Breadth-first search (BFS) is an algorithm for traversing or
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

class BFS{
private:
  Graph graph;

public:
  BFS(Graph g){
    graph = g;
  }

  vector<int> bfsFrom(const int &src){
    unordered_set<int> visited;
    queue<int> to_walk;
    vector<int> to_return;

    to_walk.push(src);

    while(!to_walk.empty()){
      int actual = to_walk.front();
      to_walk.pop();

      if(visited.find(actual)==visited.end()){
        to_return.push_back(actual);
        visited.insert(actual);

        vector<int> neighbors = graph.getNeighbors(actual);
        for(auto neighbor : neighbors){
          to_walk.push(neighbor);
        }
      }
    }

    return to_return;
  }
};

void printVec(const vector<int> &vec){
  for(auto val : vec){
    cout<<val<<" ";
  }
  cout<<endl;
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

  BFS bfs(graph);
  printVec(bfs.bfsFrom(1));

  return 0;
}
