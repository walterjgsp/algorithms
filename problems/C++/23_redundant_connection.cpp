//Problem Statement
//
// In this problem, a tree is an undirected graph that is connected and has no cycles.
// The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N),
// with one additional edge added. The added edge has two different vertices chosen
// from 1 to N, and was not an edge that already existed.
//
// The resulting graph is given as a 2D-array of edges. Each element of edges is
// a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.
//
// Return an edge that can be removed so that the resulting graph is a tree of
// N nodes. If there are multiple answers, return the answer that occurs last in
// the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  vector<int> parent;
public:
  int find(int index){
    if(parent[index]==-1)
      return index;
    return find(parent[index]);
  }

  void Union(int x, int y){
    int xroot = find(x);
    int yroot = find(y);

    if(xroot!=yroot){
      parent[xroot]=yroot;
    }
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      parent = vector<int> (edges.size()+1,-1);

      for(auto edge : edges){
        int xroot = find(edge[0]);
        int yroot = find(edge[1]);

        if(xroot==yroot)
          return edge;

        Union(xroot,yroot);
      }

      vector<int> empty;
      return empty;
  }
};

void printVec(const vector<int> &vec){
  for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
}

int main(){
  vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
  Solution sol;
  vector<int> result = sol.findRedundantConnection(edges);
  printVec(result);

  return 0;
}
