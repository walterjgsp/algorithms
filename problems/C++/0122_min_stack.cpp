// Problem Statement
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     getMin() -- Retrieve the minimum element in the stack.
#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> curr_stack;
    stack<int> min_stack;

public:
    MinStack() {
    }
    
    void push(int x) {
        curr_stack.push(x);
        int min_val = x;
        if(!min_stack.empty()){
            min_val = min(min_stack.top(),x);
        }
        min_stack.push(min_val);
    }
    
    void pop() {
        if(!curr_stack.empty()){
            curr_stack.pop();
            min_stack.pop();
        }
    }
    
    int top() {
        return curr_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl;  
    minStack.pop();
    cout<<minStack.top()<<endl;      
    cout<<minStack.getMin()<<endl;   
    return 0;
}