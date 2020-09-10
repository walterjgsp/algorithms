#include "../../problems/0175_minimum_insertions_balance_parentheses.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE("Minimum Insertions to Balance a Parentheses String") {
    Solution sol;

    REQUIRE(sol.minInsertions("(()))") == 1);
    REQUIRE(sol.minInsertions("())") == 0);
    REQUIRE(sol.minInsertions("))())(") == 3);
    REQUIRE(sol.minInsertions("((((((") == 12);
    REQUIRE(sol.minInsertions(")))))))") == 5);
    REQUIRE(sol.minInsertions("(((()(()((())))(((()())))()())))(((()(()()((()()))") == 31);
    REQUIRE(sol.minInsertions(")(()))(()))()())))") == 6);
}