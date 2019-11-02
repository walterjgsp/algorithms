
#include "../../problems/0012_find_minimum_in_rotated_sorted_array.hpp"
#include <bits/stdc++.h>
#include "../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Find Minimum In Rotated Sorted Array" ) {
    Solution sol;
    REQUIRE( sol.findMin({4,5,6,1,2,3}) == 1 );
    REQUIRE( sol.findMin({4,5,6,2,3}) == 2 );
    REQUIRE( sol.findMin({0,2,3,4,5,6}) == 0 );
    REQUIRE( sol.findMin({2,3,4,5,6,1}) == 1 );
}