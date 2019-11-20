#include "../../problems/0148_number_of_closed_islands.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Number of Closed Islands" ) {
    Solution sol;

    vector<vector<int>> grid1 = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    vector<vector<int>> grid2 = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};
    REQUIRE( sol.closedIsland(grid1) == 2 );
    REQUIRE( sol.closedIsland(grid2) == 1);
}