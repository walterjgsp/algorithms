//Problem Statement

// There are n servers numbered from 0 to n-1 connected by undirected server-to-server 
// connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. 
// Any server can reach any other server directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some server unable to reach some other server.

// Return all critical connections in the network in any order.
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> createGraph(const int &n, const vector<vector<int>>& connections){
        vector<vector<int>> graph(n);
        
        for(auto connect : connections){
            graph[connect[0]].push_back(connect[1]);
            graph[connect[1]].push_back(connect[0]);
        }
        
        return graph;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        auto graph = createGraph(n,connections);
        
        vector<bool> visited(n,false);
        vector<int> enterTime(n,-1), minEnter(n);
        vector<vector<int>> result;
        int timestamp = 0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                stack<pair<int,int>> dfs;
                dfs.push({i,i});
                
                while(!dfs.empty()){
                    auto curr_parent = dfs.top();
                    int curr = curr_parent.first;
                    int parent = curr_parent.second;
                    
                    if(visited[curr]){
                        dfs.pop();
                        minEnter[parent] = min(minEnter[curr],minEnter[parent]);
                        if(minEnter[curr]>enterTime[parent]){
                            result.push_back({parent,curr});
                        }
                    }else{
                        visited[curr]=true;
                        enterTime[curr] = minEnter[curr] = timestamp++;
                        for(auto to : graph[curr]){
                            if(to==parent)
                                continue;
                            else if(visited[to]){
                                minEnter[curr] = min(minEnter[curr],minEnter[to]);
                            }else{
                                dfs.push({to,curr});
                            }
                        }
                    }
                }
            }
        }
        
        return result;
    }
};

void printVec(const vector<vector<int>> &vec){
    for(auto v : vec){
        cout<<"{"<<v[0]<<","<<v[1]<<"} ";
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    Solution sol;
    printVec(sol.criticalConnections(4,connections));
    return 0;
}