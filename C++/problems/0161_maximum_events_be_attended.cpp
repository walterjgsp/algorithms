//Problem Statement

// Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

// Return the maximum number of events you can attend.
#include "0161_maximum_events_be_attended.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maxEvents(vector<vector<int>>& events){
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(events.begin(),events.end());

    int result=0,index=0,curr_day=1;

    while(!pq.empty() || index < events.size()){
        if(pq.empty()){
            curr_day = events[index][0];
        }

        while(index<events.size() && events[index][0] <= curr_day){
            pq.push(events[index][1]);
            index++;
        }

        pq.pop();
        result++;
        curr_day++;

        while(!pq.empty() && pq.top() < curr_day){
            pq.pop();
        }
    }

    return result;
}