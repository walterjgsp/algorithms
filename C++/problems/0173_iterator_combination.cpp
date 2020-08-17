//Problem Statement
// Design an Iterator class, which has:

// A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a next combination.
#include "0173_iterator_combination.hpp"
#include <bits/stdc++.h>

using namespace std;


void CombinationIterator::walkToNext(){
    int sub = 1,index = indexes.size()-1;
    while(index>0 && indexes[index]==start_string.size()-sub){
        index--;
        sub++;
    }
    
    indexes[index]++;
    for(int i = index+1;i<indexes.size();i++){
        indexes[i]=indexes[i-1]+1;
    }
}

CombinationIterator::CombinationIterator(string characters, int combinationLength){
    start_string = characters;
    indexes = vector<int>(combinationLength);
    for(int i=0;i<indexes.size();i++){
        indexes[i]=i;
    }
}

string CombinationIterator::next(){
 string next_string;
    for(auto i : indexes){
        next_string.push_back(start_string[i]);
    }
    walkToNext();
    return next_string;
}
    
bool CombinationIterator::hasNext(){
    return indexes[0]<=(start_string.size()-indexes.size());
}