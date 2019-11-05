//Problem Statement
// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its
// capacity, it should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
private:
  struct Node{
    int key, val;
    Node(int k, int v){
      key = k, val = v;
    }
  };
  unordered_map<int, std::list<Node>::iterator> mapping;
  list<Node> lru;
  int maxSize;

public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }

    int get(int key) {
        if(mapping.find(key)!=mapping.end()){
          int val = mapping[key]->val;
          lru.erase(mapping[key]);
          addFront(key,val);
          return val;
        }
        return -1;
    }

    int removeBack(){
      auto it = lru.back();
      int key = it.key;
      lru.pop_back();
      return key;
    }

    void addFront(int key, int val){
      lru.push_front(Node(key,val));
      mapping[key]=lru.begin();
    }

    void put(int key, int value) {
        if(mapping.find(key)!=mapping.end()){
          lru.erase(mapping[key]);
        }else if(lru.size()>=maxSize){
          mapping.erase(removeBack());
        }

        addFront(key,value);
    }
};

int main(){
  LRUCache cache( 2 );
  cache.put(1, 1);
  cache.put(2, 2);
  cout<<cache.get(1)<<endl;
  cache.put(3, 3);
  cout<<cache.get(2)<<endl;
  cache.put(4, 4);    // evicts key 1
  cout<<cache.get(1)<<endl;       // returns -1 (not found)
  cout<<cache.get(3)<<endl;       // returns 3
  cout<<cache.get(4)<<endl;
}
