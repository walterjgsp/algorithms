+++
title = "Is Graph Bipartite"
description = "Given an undirected graph, return true if and only if it is bipartite."
date = 2019-10-07T08:55:56-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/is-graph-bipartite/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

<h2 class="title is-5"> Solution </h2>

This problem can be solved coloring the graph using a bfs, if in some point of our coloring we have a vertex neighboor that is already colored and the color is the same as the current 
vertex the graph is not biparatite. Otherwise, we return true.

{{< highlight cpp >}}
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
{{< /highlight >}}

Time Complexity: **O(V+E)**