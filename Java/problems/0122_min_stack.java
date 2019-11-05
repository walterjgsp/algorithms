// Problem Statement
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     getMin() -- Retrieve the minimum element in the stack.
import java.util.Stack;

class Main{

    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        System.out.println(minStack.getMin());  
        minStack.pop();
        System.out.println(minStack.top());      
        System.out.println(minStack.getMin());  
    }
}

class MinStack {

    private Stack<Integer> currStack = new Stack<Integer>();
    private Stack<Integer> minStack = new Stack<Integer>();
    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int x) {
        currStack.push(x);
        int minValue = x;
        if(!minStack.isEmpty()){
            minValue = Math.min(minValue,minStack.peek());
        }
        minStack.push(minValue);
    }
    
    public void pop() {
        if(!currStack.isEmpty()){
            currStack.pop();
            minStack.pop();
        }
    }
    
    public int top() {
        return currStack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}