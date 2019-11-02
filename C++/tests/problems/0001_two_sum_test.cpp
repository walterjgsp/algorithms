#define CATCH_CONFIG_MAIN

#include "../../problems/0001_two_sum.hpp"
#include <bits/stdc++.h>
#include "../frameworks/catch.hpp"
#include "../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Two sum are tested" ) {
    Solution sol;
    REQUIRE( areVectorsEqual(sol.twoSum({2,11,7,15},9),{0,2}) );
    REQUIRE( areVectorsEqual(sol.twoSum({2,11,7,15},10),{}) );
    REQUIRE( areVectorsEqual(sol.twoSum({1,5,6,7,1,4,2,11,7,15},9),{1,5}) );
    REQUIRE( areVectorsEqual(sol.twoSum({2},2),{}) );
    REQUIRE( areVectorsEqual(sol.twoSum({},9),{}) );
}
