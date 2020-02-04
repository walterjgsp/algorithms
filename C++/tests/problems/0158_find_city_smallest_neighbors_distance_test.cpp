#include "../../problems/0158_find_city_smallest_neighbors_distance.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Find City With Smallest Number of Neighbors at a Distance" ) {
    Solution sol;
    
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    REQUIRE( sol.findTheCity(4,edges1,4) == 3 );   

    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    REQUIRE( sol.findTheCity(5,edges2,2) == 0 );    
}