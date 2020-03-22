#include "../../problems/0164_sort_integers_power_value.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Sort Integers by The Power Value" ) {
    Solution sol;
    
    REQUIRE( sol.getKth(12,15,2) == 13 );   

    REQUIRE( sol.getKth(1,1,1) == 1 );   

    REQUIRE( sol.getKth(7,11,4) == 7 );   

    REQUIRE( sol.getKth(10,20,5) == 13 );   

    REQUIRE( sol.getKth(1,1000,777) == 570 );   
}