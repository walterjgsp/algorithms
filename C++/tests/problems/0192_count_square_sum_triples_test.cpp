#include "../../problems/0192_count_square_sum_triples.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Count Square Sum Triples") {
    Solution sol;

    REQUIRE(sol.countTriples(5) == 2);
    REQUIRE(sol.countTriples(10) == 4);
}
