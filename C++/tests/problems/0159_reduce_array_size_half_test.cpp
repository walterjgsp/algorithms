#include "../../problems/0159_reduce_array_size_half.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Reduce Array Size to The Half" ) {
    Solution sol;
    
    vector<int> arr1 = {3,3,3,3,5,5,5,2,2,7};
    REQUIRE( sol.minSetSize(arr1) == 2 );   

    vector<int> arr2 = {7,7,7,7,7,7};
    REQUIRE( sol.minSetSize(arr2) == 1 );    

    vector<int> arr3 = {1,9};
    REQUIRE( sol.minSetSize(arr3) == 1 );  

    vector<int> arr4 = {1000,1000,3,7};
    REQUIRE( sol.minSetSize(arr4) == 1 );   

    vector<int> arr5 = {1,2,3,4,5,6,7,8,9,10};
    REQUIRE( sol.minSetSize(arr5) == 5 );       
}