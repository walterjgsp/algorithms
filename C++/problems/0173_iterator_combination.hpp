#ifndef ITERATOR_COMBINATION_HPP_INCLUDED
#define ITERATOR_COMBINATION_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class CombinationIterator {
private:
    string start_string;
    vector<int> indexes;
    void walkToNext();

public:
    CombinationIterator(string characters, int combinationLength);
    string next();
    bool hasNext();
};

#include "0173_iterator_combination.cpp"

#endif