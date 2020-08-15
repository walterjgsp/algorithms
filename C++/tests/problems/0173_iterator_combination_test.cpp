#include "../../problems/0173_iterator_combination.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Iterator for Combination" ) {
    CombinationIterator comb("abc",2);

    REQUIRE(comb.hasNext());
    REQUIRE(comb.next() == "ab");   
    REQUIRE(comb.hasNext());
    REQUIRE(comb.next() == "ac");   
    REQUIRE(comb.hasNext());
    REQUIRE(comb.next() == "bc");   
    REQUIRE(!comb.hasNext());
}