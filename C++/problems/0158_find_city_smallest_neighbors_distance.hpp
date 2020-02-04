#ifndef FIND_CITY_SMALLEST_NEIGHBORS_DISTANCE_HPP_INCLUDED
#define FIND_CITY_SMALLEST_NEIGHBORS_DISTANCE_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    int reachableCities(int start, const int & maxDistance,const vector<vector<pair<int,int>>> &graph);
    int countCities(const int &start, const int &maxDistance,const vector<int> &distances);
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold);
};

#include "0158_find_city_smallest_neighbors_distance.cpp"

#endif