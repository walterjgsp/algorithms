#include "../../problems/0184_maximum_score_removing_stones.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Score From Removing Stones" ) {
    Solution sol;

    REQUIRE(sol.maximumScore(2,4,6) == 6);
    REQUIRE(sol.maximumScore(4,4,6) == 7);
    REQUIRE(sol.maximumScore(1,8,8) == 8);
}