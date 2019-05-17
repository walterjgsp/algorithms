#include<bits/stdc++.h>

using namespace std;

class Heap{
private:
    vector<int> heap;
    bool isMinHeap;

    void heapifyUp(int index){
        if(index != 0){
            int parent = (index-1)/2;
            if(compare(heap[index],heap[parent])){
                swap(heap[parent],heap[index]);
                heapifyUp(parent);
            }
        }
    }

    void heapifyDown(int index){
        if(index<heap.size()){
            int left = 2*index+1, right = 2*index+2;
            vector< pair<int,int> > children;
            
            if(left<heap.size()){
                children.push_back(make_pair(heap[left],left));
            }

            if(right<heap.size()){
                children.push_back(make_pair(heap[right],right));
            }

            if(!children.empty()){
                int maxIndex = 0;
                for(int i=1;i<children.size();i++){
                    if(compare(children[i].first,children[maxIndex].first)){
                        maxIndex = i;
                    }
                }

                int toHeapify = children[maxIndex].second;
                if(compare(heap[toHeapify],heap[index])){
                    swap(heap[index],heap[toHeapify]);
                    heapifyDown(toHeapify);
                }
            }
        }
    }

    bool compare(const int &v1, const int &v2){
        if(isMinHeap){
            return v1<v2;
        }
        return v1>v2;
    }

public:
    Heap(bool minHeap = false){
        heap.clear();
        isMinHeap = minHeap;
    }

    void push(const int &value){
        heap.push_back(value);
        heapifyUp(heap.size()-1);
    }

    void pop(){
        if(heap.empty())
            return;

        heap.front() = heap.back();
        heap.pop_back();
        if(!heap.empty()){
            heapifyDown(0);
        }
    }

    int peek(){
        if(heap.empty()){
            return -1;
        }
        return heap.front();
    }

    void printHeap(){
        for(auto val : heap){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){

    Heap heap(true);
    heap.push(4);
    heap.push(1);
    heap.push(6);
    heap.push(2);
    heap.push(3);
    heap.push(10);
    while(!heap.empty()){
        cout<<heap.peek()<<" "; 
        heap.pop();  
    }
     
    return 0;
}