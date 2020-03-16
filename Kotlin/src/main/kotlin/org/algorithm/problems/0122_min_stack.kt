// Problem Statement
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     getMin() -- Retrieve the minimum element in the stack.
package org.algorithm.problems

import java.util.Stack;

class `0122_min_stack` {

    private val currStack = Stack<Int>()
    private val minStack = Stack<Int>()

    fun push(x: Int) {
        currStack.push(x)
        var minValue = x
        if (!minStack.isEmpty()) {
            minValue = minOf(minValue, minStack.peek())
        }
        minStack.push(minValue)
    }

    fun pop() {
        if (!currStack.isEmpty()) {
            currStack.pop()
            minStack.pop()
        }
    }

    fun top(): Int {
        return currStack.peek()
    }

    fun getMin(): Int {
        return minStack.peek()
    }
}