// Problem Statement
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
// represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and 
// whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
#include "0158_find_city_smallest_neighbors_distance.hpp"
#include <bits/stdc++.h>

int Solution::countCities(const int &start, const int &maxDistance, const vector<int> &distances){
    int result = 0;
    for(int i=0;i<distances.size();i++){
        if(i!=start && distances[i]<=maxDistance){
            result++;
        }
    }
    return result;
}
    
int Solution::reachableCities(int start, const int & maxDistance,const vector<vector<pair<int,int>>> &graph){
    vector<int> distances = vector<int>(graph.size(),INT_MAX);
    unordered_set<int> visited;
    
    distances[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dk;
    dk.push({0,start});
    
    while(!dk.empty()){
        auto curr_node = dk.top();
        dk.pop();
        
        int curr_vertex = curr_node.second;
        int curr_weight = curr_node.first;
        
        if(visited.find(curr_vertex)==visited.end()){
            visited.insert(curr_vertex);
            
            for(auto neigh : graph[curr_vertex]){
                int next_vertex = neigh.first;
                int next_dist = curr_weight + neigh.second;
                if(visited.find(next_vertex)==visited.end()){
                    distances[next_vertex] = min(next_dist,distances[next_vertex]);
                    dk.push({next_dist,next_vertex});
                }
            }
        }
    }
    
    int cities = countCities(start,maxDistance,distances);
    
    return cities;
}

int Solution::findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int,int>>> graph = vector<vector<pair<int,int>>>(n);
    int result = 0;
    int minCities = INT_MAX;
    
    for(auto edge : edges){
        graph[edge[0]].push_back({edge[1],edge[2]});
        graph[edge[1]].push_back({edge[0],edge[2]});
    }
    
    for(int i=0;i<n;i++){
        int currCities = reachableCities(i,distanceThreshold,graph);
        if(currCities<=minCities){
            minCities = currCities;
            result = i;
        }
    }
    
    return result;
}