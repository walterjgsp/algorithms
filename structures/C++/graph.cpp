#include <bits/stdc++.h>

using namespace std;

class GraphAdjList{
private:
  vector<vector<int>> adjList;
  
public:
  GraphAdjList(int vertexes){
    adjList = vector<vector<int>> (vertexes);
  }

  void addEdge(int start, int end){
    adjList[start].push_back(end);
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

class GraphAdjMatrix{
private:
  vector<vector<int>> adjMatrix;
public:
  GraphAdjMatrix(int vertexes){
    adjMatrix = vector<vector<int>>(vertexes,vector<int>(vertexes,0));
  }

  void addEdge(int start,int end){
    adjMatrix[start][end]=1;
  }

  void printGraph(){
    for(int i=0;i<adjMatrix.size();i++){
      cout<<i<<": ";
      for(int j=0;j<adjMatrix[i].size();j++){
        if(adjMatrix[i][j]!=0){
          cout<<j<<"->";
        }
      }
      cout<<"NULL"<<endl;
    }
  }
};

int main(){

  cout<<"Adjacency List"<<endl<<endl;

  GraphAdjList graph(4);

  graph.addEdge(0,3);
  graph.addEdge(0,2);
  graph.addEdge(1,3);
  graph.addEdge(3,2);

  graph.printGraph();

  cout<<endl<<"Adjacency Matrix"<<endl<<endl;

  GraphAdjMatrix graphM(4);

  graphM.addEdge(0,3);
  graphM.addEdge(0,2);
  graphM.addEdge(1,3);
  graphM.addEdge(3,2);

  graphM.printGraph();

  return 0;
}
