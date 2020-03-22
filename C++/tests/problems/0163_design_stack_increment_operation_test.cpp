#include "../../problems/0163_design_stack_increment_operation.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Design a Stack With Increment Operation" ) {
    CustomStack *customStack = new CustomStack(3);
    
    customStack->push(1);                          // stack becomes [1]
    customStack->push(2);                          // stack becomes [1, 2]
    REQUIRE( customStack->pop() == 2 ); 
    customStack->push(2);                          // stack becomes [1, 2]
    customStack->push(3);                          // stack becomes [1, 2, 3]
    customStack->push(4);                          // stack still [1, 2, 3], Don't add another 
    customStack->increment(5, 100);                // stack becomes [101, 102, 103]
    customStack->increment(2, 100);                // stack becomes [201, 202, 103]
    REQUIRE( customStack->pop() == 103 );          // return 103 --> Return top of the stack 103, stack becomes [201, 202]
    REQUIRE( customStack->pop() == 202 );          // return 202 --> Return top of the stack 102, stack becomes [201]
    REQUIRE( customStack->pop() == 201 );          // return 201 --> Return top of the stack 101, stack becomes []
    REQUIRE( customStack->pop() == -1 );           // return -1 --> Stack is empty return -1.
}