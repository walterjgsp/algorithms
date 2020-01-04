// Problem Statement
// In a country popular for train travel, you have planned some train travelling one year in advance.  
// The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

// Train tickets are sold in 3 different ways:

// a 1-day pass is sold for costs[0] dollars;
// a 7-day pass is sold for costs[1] dollars;
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, 
// then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

// Return the minimum number of dollars you need to travel every day in the given list of days.
#include "0156_minimum_cost_tickets.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::dp(int index,map<int,int> &memo,const vector<int> &days,const vector<int> &costs, const vector<int> &pass){
    if(index>=days.size())
        return 0;
    
    if(memo.find(index)!=memo.end())
        return memo[index];
    
    int j=index,result=INT_MAX;
    for(int i=0;i<pass.size();i++){
        while(j<days.size() && days[j]<days[index]+pass[i])
            j++;
        result = min(result,dp(j,memo,days,costs,pass)+costs[i]);
    }
    
    return memo[index]=result;
}

int Solution::mincostTickets(vector<int> days, vector<int> costs) {
    map<int,int> memo;
    vector<int> pass = {1,7,30};
    
    return dp(0,memo,days,costs,pass);
}