// Problem Statement
// Design your implementation of the circular queue. The circular queue is a linear data structure in which 
// the operations are performed based on FIFO (First In First Out) principle and the last position 
// is connected back to the first position to make a circle. It is also called "Ring Buffer".

// One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal 
// queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the 
// queue. But using the circular queue, we can use the space to store new values.

// Your implementation should support following operations:

//     MyCircularQueue(k): Constructor, set the size of the queue to be k.
//     Front: Get the front item from the queue. If the queue is empty, return -1.
//     Rear: Get the last item from the queue. If the queue is empty, return -1.
//     enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
//     deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
//     isEmpty(): Checks whether the circular queue is empty or not.
//     isFull(): Checks whether the circular queue is full or not.

#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
private:
    vector<int> m_queue;
    int start, end, filled;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        m_queue = vector<int>(k);
        start = end = filled = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(filled<m_queue.size()){
            m_queue[end]=value;
            end = (end+1)%m_queue.size();
            filled++;
            return true;
        }
        
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(filled>0){
            start = (start+1)%m_queue.size();
            filled--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(filled>0){
            return m_queue[start];
        }
        
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(filled>0){
            int last_index = end-1<0 ? m_queue.size()-1 : end -1; 
            return m_queue[last_index];
        }
        
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return filled==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return filled==m_queue.size();
    }
};