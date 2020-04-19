#include "../../problems/0166_reformat_string.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Reformat The String" ) {
    Solution sol;
    
    REQUIRE( sol.reformat("a0b1c2") == "c2b1a0" );   

    REQUIRE( sol.reformat("leetcode") == "" );  

    REQUIRE( sol.reformat("1229857369") == "" );   

    REQUIRE( sol.reformat("covid2019") == "d9i1v0o2c" );   

    REQUIRE( sol.reformat("ab123") == "3b2a1" );   

}