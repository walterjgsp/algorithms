// Problem Statement
// LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, 
// the security system saves the worker's name and the time when it was used. 
// The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

// You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a 
// person's name and the time when their key-card was used in a single day.

// Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

// Return a list of unique worker names who received an alert for frequent keycard use. 
// Sort the names in ascending order alphabetically.

// Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" 
// is not considered to be within a one-hour period.
#include "0180_alert_key_three_times.hpp"
#include <bits/stdc++.h>

using namespace std;


int Solution::parseTime(string keyTime){
    int hour = stoi(keyTime.substr(0,2));
    int minutes = stoi(keyTime.substr(3,2));
    return hour*60+minutes;
}

bool Solution::needToAlert(set<int> usage){
    deque<int> window;
    
    for(auto use : usage){
        window.push_back(use);
        
        while(!window.empty() && window.back()-window.front()>60){
            window.pop_front();
        }
        
        if(window.size() == 3 && window.back()-window.front()<=60){
            return true;
        }
    }
    
    return false;
}

vector<string> Solution::alertNames(vector<string>& keyName, vector<string>& keyTime){
    map<string,set<int>> usage;
    vector<string> result;
    
    for(int i=0;i<keyName.size();i++){
        auto curr_name = keyName[i];
        auto curr_time = parseTime(keyTime[i]);
        
        usage[curr_name].insert(curr_time);
    }
    
    for(auto it : usage){
        auto curr_name = it.first;
        auto use = it.second;
        
        if(needToAlert(use)){
            result.push_back(curr_name);
        }
    }
    
    return result;
}