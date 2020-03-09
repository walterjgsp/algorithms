#include "../../problems/0160_product_last_k_numbers.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Product of the Last K Numbers" ) {
    ProductOfNumbers productOfNumbers;
    
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]

    REQUIRE( productOfNumbers.getProduct(2) == 20 );   
    REQUIRE( productOfNumbers.getProduct(3) == 40 );    
    REQUIRE( productOfNumbers.getProduct(4) == 0 );  

    productOfNumbers.add(8);        // [3,0,2,5,4,8]

    REQUIRE( productOfNumbers.getProduct(2) == 32 );   
}