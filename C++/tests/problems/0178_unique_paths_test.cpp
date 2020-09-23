#include "../../problems/0178_unique_paths.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Unique Paths" ) {
    Solution sol;

    REQUIRE(sol.uniquePaths(3,7)==28); 

    REQUIRE(sol.uniquePaths(3,2)==3); 

    REQUIRE(sol.uniquePaths(7,3)==28);   

    REQUIRE(sol.uniquePaths(3,3)==6);  
}