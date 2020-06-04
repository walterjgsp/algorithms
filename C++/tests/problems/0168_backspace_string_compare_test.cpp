#include "../../problems/0168_backspace_string_compare.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Backspace String Compare" ) {
    Solution sol;
    
    REQUIRE(sol.backspaceCompare("ab#c","ad#c"));   

    REQUIRE(sol.backspaceCompare("ab##","c#d#"));   
    
    REQUIRE(sol.backspaceCompare("a##c","#a#c"));   
    
    REQUIRE(!sol.backspaceCompare("a#c","b"));   
}