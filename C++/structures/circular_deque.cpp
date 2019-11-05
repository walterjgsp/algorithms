#include<bits/stdc++.h>

using namespace std;

class CircularDeque {
private:
    vector<int> container;
    int start,end,count;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    CircularDeque(int k) {
        container = vector<int>(k);
        start = end = count = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        
        start = (start-1)>=0 ? start-1 : container.size()-1;
        container[start] = value;
        count++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        
        container[end]=value;
        end = (end+1)%container.size();
        count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        
        start = (start+1)%container.size();
        count--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        
        end = (end-1)>=0 ? end-1 : container.size()-1;
        count--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        
        return container[start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        
        int last_index = (end-1)>=0 ? end-1 : container.size()-1;
        return container[last_index];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == container.size();
    }
};
