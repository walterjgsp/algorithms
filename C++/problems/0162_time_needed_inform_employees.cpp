//Problem Statement
// A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company has is the one with headID.

// Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also it's guaranteed that the subordination relationships have a tree structure.

// The head of the company wants to inform all the employees of the company of an urgent piece of news. He will inform his direct subordinates and they will inform their subordinates and so on until all employees know about the urgent news.

// The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e After informTime[i] minutes, all his direct subordinates can start spreading the news).

// Return the number of minutes needed to inform all the employees about the urgent news.

#include "0162_time_needed_inform_employees.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
    unordered_map<int,vector<int>> children;
    int result = 0;
    
    for(int i=0;i<manager.size();i++){
        if(manager[i]!=-1){
            children[manager[i]].push_back(i);
        }
    }
    
    queue<pair<int,int>> bfs;
    bfs.push({headID,0});
    
    while(!bfs.empty()){
        auto curr_node = bfs.front();
        bfs.pop();
        auto child_list = children[curr_node.first];
        if(!child_list.empty()){
            for(auto child : child_list){
                bfs.push({child,informTime[curr_node.first]+curr_node.second});
            }
        }else{
            result = max(result,curr_node.second);
        }
    }
    return result;
}