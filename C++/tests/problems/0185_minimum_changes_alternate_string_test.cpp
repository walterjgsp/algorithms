#include "../../problems/0185_minimum_changes_alternate_string.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimum Changes To Make Alternating Binary String" ) {
    Solution sol;

    REQUIRE(sol.minOperations("0100") == 1);
    REQUIRE(sol.minOperations("01") == 0);
    REQUIRE(sol.minOperations("1111") == 2);
}