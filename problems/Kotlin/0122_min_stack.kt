// Problem Statement
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     getMin() -- Retrieve the minimum element in the stack.

import java.util.Stack;

class MinStack() {

    private val currStack = Stack<Int>()
    private val minStack = Stack<Int>()

    fun push(x: Int) {
        currStack.push(x)
        var minValue = x
        if(!minStack.isEmpty()){
            minValue = minOf(minValue,minStack.peek())
        }
        minStack.push(minValue)
    }

    fun pop() {
        if(!currStack.isEmpty()){
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

fun main(args: Array<String>) {
    val minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    println(minStack.getMin());  
    minStack.pop();
    println(minStack.top());      
    println(minStack.getMin());   
}