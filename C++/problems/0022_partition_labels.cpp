// Problem Statement
//
// A string S of lowercase letters is given. We want to partition this string into
// as many parts as possible so that each letter appears in at most one part,
// and return a list of integers representing the size of these parts.
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
#include "0022_partition_labels.hpp"
#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::partitionLabels(string S) {
    vector<int> result;

    if (S.empty())return result;

    vector <pair<int, int>> intervals(26, {-1, -1});
    priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair < int, int>> > pq;

    for (int i = 0; i < S.size(); i++) {
        int index = S[i] - 'a';
        if (intervals[index].first == -1) {
            intervals[index].first = i;
        }
        intervals[index].second = i;
    }

    for (auto it : intervals) {
        if (it.first != -1) {
            pq.push(it);
        }
    }

    pair<int, int> curr_inter = pq.top();
    pq.pop();
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (curr_inter.second > top.first) {
            curr_inter.second = max(curr_inter.second, top.second);
        } else {
            result.push_back(curr_inter.second - curr_inter.first + 1);
            curr_inter = top;
        }
    }
    result.push_back(curr_inter.second - curr_inter.first + 1);
    return result;
}

