#ifndef NUMBER_OF_CLOSED_ISLANDS_HPP_INCLUDED
#define NUMBER_OF_CLOSED_ISLANDS_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Solution{
private:
    vector<int> dir = {0,1,0,-1,0};

    void bfs(vector<vector<int>> &grid, int row, int col, int value);

public:
    int closedIsland(vector<vector<int>>& grid);
};

#include "0148_number_of_closed_islands.cpp"

#endif