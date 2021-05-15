//Problem Statement
//
//You are given a 2D integer array logs where each logs[i] = [birthi, deathi]
//indicates the birth and death years of the ith person.
//
//The population of some year x is the number of people alive during that year.
//The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1].
//Note that the person is not counted in the year that they die.
//
//Return the earliest year with the maximum population.

#include "0189_maximum_population_year.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maximumPopulation(vector<vector<int>>& logs){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
    int result, current_year = 0, current_live = 0, max_alive = 0;

    for(auto log : logs){
        pq.push({log[0],0});
        pq.push({log[1],1});
    }

    while(!pq.empty()){
        auto top = pq.top();

        current_year = top.first;
        while(top.first == current_year && !pq.empty()){
            if(top.second == 0){
                current_live++;
            }else{
                current_live--;
            }
            pq.pop();
            top = pq.top();
        }

        if(current_live > max_alive){
            result = current_year;
            max_alive = current_live;
        }
    }

    return result;
}
