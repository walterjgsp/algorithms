#ifndef NUMBER_OPERATIONS_NETWORK_CONNECTED_HPP_INCLUDED
#define NUMBER_OPERATIONS_NETWORK_CONNECTED_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    vector<int> parent;

    int find(int x);
    void Union(int x, int y);
    int countClusters();

public:
    int makeConnected(int n, vector<vector<int>>& connections);
};

#include "0157_number_operations_network_connected.cpp"

#endif