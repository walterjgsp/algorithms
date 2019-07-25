// Problem Statement
// Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  
// In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.

// Each [i, j] in red_edges denotes a red directed edge from node i to node j.  
// Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

// Return an array answer of length n, where each answer[X] is the length of the shortest path 
// from node 0 to node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    enum Color{RED,BLUE};

    void populateGraph(vector<vector<int>> &edges, unordered_map<int,vector<int>> &graph){
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> result (n,-1);
        unordered_map<int,vector<int>> red_graph,blue_graph;

        populateGraph(red_edges,red_graph);
        populateGraph(blue_edges,blue_graph);

        unordered_set<int> from_red,from_blue;
        
        queue<pair<int,Color>> bfs;
        
        for(auto neigh : red_graph[0]){
            bfs.push(make_pair(neigh,RED));
        }
        
        for(auto neigh : blue_graph[0]){
            bfs.push(make_pair(neigh,BLUE));
        }
        
        int length = 1;
        result[0]=0;
        
        while(!bfs.empty()){
            int tam = bfs.size();
            for(int i=0;i<tam;i++){
                
                auto curr = bfs.front();
                bfs.pop();
                
                if(result[curr.first]==-1){
                    result[curr.first]=length;
                }
                
                if(curr.second == RED){
                    from_red.insert(curr.first);
                    for(auto neigh : blue_graph[curr.first]){
                        if(from_blue.find(neigh)==from_blue.end()){
                            bfs.push(make_pair(neigh,BLUE)); 
                        }
                    }
                }else{
                    from_blue.insert(curr.first);
                    for(auto neigh : red_graph[curr.first]){
                        if(from_red.find(neigh)==from_red.end()){
                            bfs.push(make_pair(neigh,RED)); 
                        }
                    }
                }
            }
            length++;
        }
        
        return result;
    }
};

void printVec(const vector<int> &vec){
    for(auto v: vec){
        cout<<v<<" ";
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> red_edges = {{0,1},{1,2},{2,3},{3,4}}, blue_edges = {{1,2},{2,3},{3,1}};
    Solution sol;
    printVec(sol.shortestAlternatingPaths(5,red_edges,blue_edges));
}