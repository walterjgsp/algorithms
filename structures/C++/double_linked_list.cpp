#include <bits/stdc++.h>

using namespace std;

template <typename T> class DoubleLinkedList{
private:
    struct Node{
        Node *prev,*next;
        T value;
        Node(T val){
            prev = nullptr,next = nullptr;
            value = val;
        }
    };
    Node *head,*tail;
    int size;

public:
    DoubleLinkedList(){
        head = nullptr,tail = nullptr;
        size = 0;
    }

    int length(){
        return size;
    }

    void printList(){
        Node *it = head;
        while(it){
            cout<<it->value<<" ";
            it = it->next;
        }
        cout<<endl;
    }

    void insert_at(int index, T val){
        Node *it = head;
        if(!it && index < 1) {
            push_front(val);
        }else if(index>=size){
            push_back(val);
        }else{
            while(index>1 && it->next){
                it = it->next;
                index--;
            }

            Node *newNode = new Node(val);
            newNode->next = it->next;
            newNode->prev = it;
            it->next = newNode;
            size++;
        }
    }

    void push_front(T val){
        Node *newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = head;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    void pop_front(){
        Node *it = head;
        if(it){
            size--;
            it = it->next;
            if(it==nullptr){
                tail = it;
            }else{
                it->prev = nullptr;
            }
        }
        head = it;
    }

    void push_back(T val){
        Node *newNode = new Node(val);
        if(!tail){
            tail = newNode;
            head = tail;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void pop_back(){
        Node *it = tail;
        if(it){
            size--;
            it = it->prev;
            if(!it){
                head = it;
            }else{
                it->next = nullptr;
            }
        }

        tail = it;
    }

    bool empty(){
        return size>0;
    }

    T back(){
        if(tail){
            return tail->value;
        }
        return nullptr;
    }

};

int main(){
    DoubleLinkedList<int> dList;
    dList.push_front(4);
    dList.push_back(3);
    dList.printList();
    dList.printList();
    dList.insert_at(0,2);
    dList.printList();
    cout<<dList.back()<<endl;

    return 0;
}