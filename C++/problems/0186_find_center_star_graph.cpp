//Problem Statement
// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a 
// graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates 
// that there is an edge between the nodes ui and vi. Return the center of the given star graph.

#include "0186_find_center_star_graph.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::findCenter(vector<vector<int>>& edges){
    vector<int> vertex(edges.size()+1);
        
    for(auto e : edges){
        vertex[e[0]-1]++;
        vertex[e[1]-1]++;
    }
    
    for(int i=0;i<vertex.size();i++){
        if(vertex[i]>1){
            return i+1;
        }
    }
    
    return 0;
}