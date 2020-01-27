#include "../../problems/0157_number_operations_network_connected.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Number of Operations to Make Network Connected" ) {
    Solution sol;
    
    vector<vector<int>> connections1 = {{0,1},{0,2},{1,2}};
    REQUIRE( sol.makeConnected(4,connections1) == 1 );   

    vector<vector<int>> connections2 = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    REQUIRE( sol.makeConnected(6,connections2) == 2 );    

    vector<vector<int>> connections3 = {{0,1},{0,2},{0,3},{1,2},{1,3},{4,5}};
    REQUIRE( sol.makeConnected(6,connections3) == 1 );

    vector<vector<int>> connections4 = {{0,1},{0,2},{0,3},{1,2}};
    REQUIRE( sol.makeConnected(6,connections4) == -1 );   

    vector<vector<int>> connections5 = {{0,1},{0,2},{3,4},{2,3}};
    REQUIRE( sol.makeConnected(5,connections5) == 0 );        
}