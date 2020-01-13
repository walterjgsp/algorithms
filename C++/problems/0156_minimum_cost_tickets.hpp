#ifndef MINIMUM_COST_TICKETS_HPP_INCLUDED
#define MINIMUM_COST_TICKETS_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    int dp(int index,map<int,int> &memo,const vector<int> &days,const vector<int> &costs, const vector<int> &pass);

public:
    int mincostTickets(vector<int> days, vector<int> costs);
};

#include "0156_minimum_cost_tickets.cpp"

#endif