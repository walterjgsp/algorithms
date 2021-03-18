#include "../../problems/0185_find_center_star_graph.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Find Center of Star Graph" ) {
    Solution sol;

    vector<vector<int>> edge1 = {{1,2},{2,3},{4,2}}
    REQUIRE(sol.findCenter(edge1) == 2);

    vector<vector<int>> edge2 = {{1,2},{5,1},{1,3},{1,4}}
    REQUIRE(sol.findCenter(edge2) == 1);
    
}