#ifndef DESIGN_STACK_INCREMENT_OPERATION_HPP_INCLUDED
#define DESIGN_STACK_INCREMENT_OPERATION_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class CustomStack {
    vector<int> st;
    int capacity;
public:
    CustomStack(int maxSize);
    void push(int x);
    int pop();
    void increment(int k, int val);
};

#include "0163_design_stack_increment_operation.cpp"

#endif