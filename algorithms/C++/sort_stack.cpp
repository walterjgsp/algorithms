// Sort stack using one temporary stack, min values on top;

#include<bits/stdc++.h>

using namespace std;

stack<int> sortStack(stack<int> s){
    if(s.empty()){
        return s;
    }
    stack<int> temp;
    int curr_value;
    int stack_size = s.size();

    while(stack_size > 0){
        curr_value = s.top();
        s.pop();
        for(int i=0;i<stack_size-1;i++){
            if(curr_value < s.top()){
                temp.push(curr_value);
                curr_value = s.top();
            }else{
                temp.push(s.top());
            }
            s.pop();
        }
        s.push(curr_value);
        stack_size--;
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
    return s;
};

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(9);
    st.push(2);
    st.push(3);
    st.push(5);
    printStack(st);
    st = sortStack(st);
    printStack(st);
    return 0;
}