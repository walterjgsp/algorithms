// Problem Statement
// Sue is a network administrator who consults for companies that have massive 
// Local Area Networks (LANs). The computers are connected together with network cables,
// and Sue has been brought in to evaluate the company’s network. The networks are huge, 
// and she wants to ensure that no single network cable failure can disconnect 
// the network. Any cable that fails that leaves the network in two or more disconnected 
// pieces is called a single point of failure.

// She labels the different network devices from 0 to n - 1. She keeps an n × n matrix 
// connections, where connections[i][j] = 1 if there is a network cable directly 
// connecting devices i and j, and 0 otherwise. Write a function that 
// takes the matrix of connections, and returns the number of cables 
// that are a single point of failure.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int singlePointOfFailure(vector<vector<int>> connections) {
        int graphSize = connections.size();
        vector<bool> visited(graphSize,false);
        vector<int> enterTime(graphSize,-1), minEnter(graphSize,-1);
        int time = 0, result = 0;
        
        stack<pair<int,int>> dfs;
        dfs.push({0,0});
        
        while(!dfs.empty()){
            auto curr_parent = dfs.top();
            int curr = curr_parent.first;
            int parent = curr_parent.second;
        
            if(visited[curr]){
                dfs.pop();
                minEnter[parent] = min(minEnter[curr],minEnter[parent]);
                if(minEnter[curr]>enterTime[parent]){
                    result++;
                }
            }else{
                visited[curr] = true;
                enterTime[curr] = minEnter[curr] = time++;
                auto neighbors = connections[curr];
                for(int i=0;i<neighbors.size();i++){
                    if(neighbors[i]==1){
                        if(i==parent)
                            continue;
                        else if(visited[i]){
                            minEnter[curr] = min(minEnter[curr],minEnter[i]);
                        }else{
                            dfs.push({i,curr});
                        }
                    }
                }
            }
        }
        
        return result;
    }
};

int main(){
    vector<vector<int>> connections =  {{0, 1, 1, 1, 0, 0}, {1, 0, 1, 0, 0, 0}, {1, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 1}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0}};
    Solution sol;

    cout<<sol.singlePointOfFailure(connections)<<endl;
    return 0;
}