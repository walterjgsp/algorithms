#include <bits/stdc++.h>

using namespace std;

class Stack{
private:
    struct SNode{
        int data;
        SNode *prev;
        SNode(const int &x){
            data = x;
            prev = nullptr;
        }
    };

    SNode *last;
    int length;

public:
    Stack(){
        last = nullptr;
        length = 0;
    }

    void push(const int &val){
        SNode *newTop = new SNode(val);
        newTop->prev = last;
        last = newTop;
        length++;
    }

    void pop(){
        if(!last)
            return;
        
        SNode *currTop = last;
        last = last->prev;
        length--;
        delete currTop;
    }

    bool empty(){
        return last == nullptr;
    }

    int top(){
        if(!last)
            return -1;
        
        return last->data;
    }
};

int main(){
    Stack st;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(4);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}