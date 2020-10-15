#ifndef ALERT_KEY_THREE_TIMES_HPP_INCLUDED
#define ALERT_KEY_THREE_TIMES_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int parseTime(string keyTime);
    bool needToAlert(set<int> usage);
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime);
};

#include "0180_alert_key_three_times.cpp"

#endif