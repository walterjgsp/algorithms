#include "../../problems/0147_maximum_product_subarray.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Product Subarray" ) {
    Solution sol;
    REQUIRE( sol.maxProduct({2,3,-2,4}) == 6 );
    REQUIRE( sol.maxProduct({2,3,-2,1,-3}) == 36 );
    REQUIRE( sol.maxProduct({-2,-3,0,-4,-5,2}) == 40 );
    REQUIRE( sol.maxProduct({-2,0,-1,8}) == 8 );
    REQUIRE( sol.maxProduct({-2,0,-1}) == 0 );
}