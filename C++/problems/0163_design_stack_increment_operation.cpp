//Problem Statement
// Design a stack which supports the following operations.

// Implement the CustomStack class:

// * CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number 
    //of elements in the stack or do nothing if the stack reached the maxSize.
// * void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
// * int pop() Pops and returns the top of stack or -1 if the stack is empty.
// * void inc(int k, int val) Increments the bottom k elements of the stack by val. 
    //If there are less than k elements in the stack, just increment all the elements in the stack.

#include "0163_design_stack_increment_operation.hpp"
#include <bits/stdc++.h>

using namespace std;

CustomStack::CustomStack(int maxSize) {
    capacity = maxSize;
}

void CustomStack::push(int x) {
    if(st.size()<capacity){
        st.push_back(x);
    }
}

int CustomStack::pop() {
    if(!st.empty()){
        int result = st.back();
        st.pop_back();
        return result;
    }
    return -1;
}

void CustomStack::increment(int k, int val) {
    for(int i=0;i<k && i<st.size();i++){
        st[i]+=val;
    }
}