#include "../../problems/0149_count_servers_communicate.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Count Servers that Communicate" ) {
    Solution sol;
    vector<vector<int>> grid1 = {{1,0},{0,1}};
    vector<vector<int>> grid2 = {{1,1},{0,1}};
    vector<vector<int>> grid3 = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    REQUIRE( sol.countServers(grid1) == 0 );
    REQUIRE( sol.countServers(grid2) == 3 );
    REQUIRE( sol.countServers(grid3) == 4 );
}