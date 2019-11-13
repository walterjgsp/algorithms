#include "../../problems/0146_minimum_remove_valid_parentheses.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimum Remove to Make Valid Parentheses" ) {
    Solution sol;
    REQUIRE( sol.minRemoveToMakeValid("lee(t(c)o)de)") == "lee(t(c)o)de" );
    REQUIRE( sol.minRemoveToMakeValid("a)b(c)d") == "ab(c)d" );
    REQUIRE( sol.minRemoveToMakeValid("))((") == "" );
    REQUIRE( sol.minRemoveToMakeValid("(a(b(c)d)") == "a(b(c)d)" );
}