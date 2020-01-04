#include "../../problems/0156_minimum_cost_tickets.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimum Cost For Tickets" ) {
    Solution sol;
    
    REQUIRE( sol.mincostTickets({1,2,3,4,5,6,7,8,9,10,30,31},{2,7,15}) == 17 );   

    REQUIRE( sol.mincostTickets({1,4,6,7,8,20},{2,7,15}) == 11 );    
     
}