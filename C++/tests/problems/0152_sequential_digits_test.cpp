#include "../../problems/0152_sequential_digits.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Sequential Digits" ) {
    Solution sol;
    
    vector<int> result1 = {123,234};
    REQUIRE( areVectorsEqual(sol.sequentialDigits(100,300),result1) );    
    
    vector<int> result2 = {1234,2345,3456,4567,5678,6789,12345};
    REQUIRE( areVectorsEqual(sol.sequentialDigits(1000,13000),result2) );    
}