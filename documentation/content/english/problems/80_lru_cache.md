+++
title = "LRU Cache"
description = "Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put."
date = 2019-03-20T21:46:11-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/lru-cache/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item.

<h2 class="title is-5"> Solution </h2>

In the LRU Cache the least used recent key is evicted from the memory. One way to keep a track of key usage is keeping the key in one
of the extremities on the selected structure to simulate the memory. Every time that a key is used (being the actions of get or put)
the value will be placed at the start, and before the put operation remove the least used key if the maximum size of the array was already
reached.

One solution is to keep an array of keys, and each time the functions are called the array is rearranged to match the condition stated.
This make the solution **O(n*m)** where n is the number of operations and m the maximum size of the cache.

If a linked list is used with an unordered map is possible to make the solution **O(1)** for both operations (get and put). The map will be
used to keep a track of all the keys in my list and the pointers to the list nodes of this keys. Every time a action is called we rearrange
only the node that was used placing it at the front of the list, and this operations are **O(1)** for a list.

{{< highlight cpp >}}
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
{{< /highlight >}}

Time complexity for both operations: **O(1)**

Space complexity : **O(n)**
