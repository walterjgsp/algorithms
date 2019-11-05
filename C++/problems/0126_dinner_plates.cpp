// Problem Statement
// You have an infinite number of stacks arranged in a row and numbered (left to right) from 0, 
// each of the stacks has the same maximum capacity.

// Implement the DinnerPlates class:

// DinnerPlates(int capacity) Initializes the object with the maximum capacity of the stacks.
// void push(int val) pushes the given positive integer val into the leftmost stack with size less than capacity.
// int pop() returns the value at the top of the rightmost non-empty stack and removes it from that stack, 
    // and returns -1 if all stacks are empty.
// int popAtStack(int index) returns the value at the top of the stack with the given index and removes 
    // it from that stack, and returns -1 if the stack with that given index is empty.
#include<bits/stdc++.h>

using namespace std;

class DinnerPlates {
private:
    vector<stack<int>> plates;
    int max_capacity;
    int index_add;

    void fixIndex(int index){
        while(!plates.empty() && plates.back().empty()){
            plates.pop_back();
        }

        int new_last_index = plates.size()-1;
        new_last_index = max(0,new_last_index);
        index_add = min(index,new_last_index);
    }

public:
    DinnerPlates(int capacity) {
        index_add = 0;
        max_capacity = capacity;
    }
    
    void push(int val) {
        if(plates.empty() || index_add >= plates.size()){
            plates.push_back(stack<int>());
        }

        plates[index_add].push(val);
        while(index_add < plates.size() && plates[index_add].size() == max_capacity){
            index_add++;
        }
    }
    
    int pop() {
        if(plates.empty()) return -1;

        int to_return = plates.back().top();
        plates.back().pop();
        fixIndex(index_add);
        return to_return;
    }
    
    int popAtStack(int index) {
        if(index >= plates.size() || plates[index].empty()) return -1;

        int to_return = plates[index].top();
        plates[index].pop();
        fixIndex(index);
        return to_return;
    }
};

void test1(){
    DinnerPlates D = DinnerPlates(2);  // Initialize with capacity = 2
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);
    cout<<D.popAtStack(0)<<endl;
    D.push(20);
    D.push(21);
    cout<<D.popAtStack(0)<<endl;
    cout<<D.popAtStack(2)<<endl;
    cout<<D.pop()<<endl;
    cout<<D.pop()<<endl;            
    cout<<D.pop()<<endl;            
    cout<<D.pop()<<endl;            
    cout<<D.pop()<<endl;
}

void test2(){
    DinnerPlates D = DinnerPlates(1);
    D.push(1);
    D.push(2);
    D.push(3);
    cout<<D.popAtStack(1)<<endl;
    cout<<D.pop()<<endl;
    cout<<D.pop()<<endl;
}

void test3(){
    DinnerPlates D = DinnerPlates(1);
    D.push(1);
    D.push(2);
    cout<<D.popAtStack(1)<<endl;
    cout<<D.pop()<<endl;
    D.push(1);
    D.push(2);
    cout<<D.pop()<<endl;
    cout<<D.pop()<<endl;
}

int main(){    
    test3();
    return 0;
}