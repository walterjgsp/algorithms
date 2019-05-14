
#include <bits/stdc++.h>

using namespace std;

class LRUCache{
private:
    struct Node{
        int key,value;
        Node(int k, int v){
            key=k,value=v;
        }
    };
    list<Node> lru;
    unordered_map<int,std::list<Node>::iterator> mapping;
    int maxSize;

    void removeKey(int key){
        auto it = mapping[key];
        lru.erase(it);
        mapping.erase(key);
    }

    void addKey(int key, int val){
        lru.push_front(Node(key,val));
        auto it = lru.begin();
        mapping[key]=it;
    }

    void removeLast(){
        auto it = lru.rbegin();
        mapping.erase(it->key);
        lru.pop_back();
    }
public:
    LRUCache(int capacity){
        maxSize = capacity;
    }

    void put(int key, int value){
        if(mapping.find(key)!=mapping.end()){
            removeKey(key);
        }else if(lru.size()>=maxSize){
            removeLast();
        }
        addKey(key,value);
    }

    int get(int key){
        int value = -1;
        if(mapping.find(key)!=mapping.end()){
            auto it = mapping[key];
            value = it->value;
            put(it->key,it->value);
        }

        return value;
    }

    void printCache(){
        for(auto it = lru.begin();it!=lru.end();it++){
            cout<<it->key<<":"<<it->value<<" ";
        }
        cout<<endl;
    }
};

int main(){
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,2);
    lru.printCache();
    cout<<lru.get(1)<<endl;
    lru.put(3,3);
    lru.printCache();
    
    return 0;
}