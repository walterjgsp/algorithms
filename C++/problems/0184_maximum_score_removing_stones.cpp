//Problem Statement
// You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. 
// Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. 
// The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).

// Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.
#include "0184_maximum_score_removing_stones.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maximumScore(int a, int b, int c){
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int result = 0;

    while(pq.size()>1){
        auto first = pq.top();
        pq.pop();
        auto second = pq.top();
        pq.pop();
        
        result++;
        first--;
        second--;
        if(first>0){
            pq.push(first);
        }
        if(second>0){
            pq.push(second);
        }
    }
    
    return result;
}