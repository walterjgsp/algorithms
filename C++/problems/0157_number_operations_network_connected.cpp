//Problem Statement
// There are n computers numbered from 0 to n-1 connected by ethernet cables connections 
// forming a network where connections[i] = [a, b] represents a connection between computers a and b. 
// Any computer can reach any other computer directly or indirectly through the network.

// Given an initial computer network connections. You can extract certain cables between two directly 
// connected computers, and place them between any pair of disconnected computers to make them directly 
// connected. Return the minimum number of times you need to do this in order to make all the computers 
// connected. If it's not possible, return -1. 
#include "0157_number_operations_network_connected.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::find(int x){
    if(parent[x]!=x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void Solution::Union(int x, int y){
    int xparent = find(x);
    int yparent = find(y);

    if(xparent!=yparent){
        parent[xparent] = yparent;
    }
}

int Solution::countClusters(){
    unordered_set<int> clusters;
    for(int i=0;i<parent.size();i++){
        int iparent = find(i);
        clusters.insert(iparent);
    }
    return clusters.size();
}

int Solution::makeConnected(int n, vector<vector<int>>& connections){
    if(connections.size()<n-1) return -1;

    parent = vector<int>(n,0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    for(auto con : connections){
        int x = con[0], y = con[1];
        Union(x,y);
    }

    int clusters = countClusters();
    return clusters-1;
}