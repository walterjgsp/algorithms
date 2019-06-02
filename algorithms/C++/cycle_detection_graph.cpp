#include <bits/stdc++.h>

using namespace std;

class CycleDetection{
public:
    bool hasCycleDFS(const vector<vector<int>> &connections){
        unordered_set<int> visited;
        vector<bool> rec_stack(connections.size(),false);

        for(int i=0;i<connections.size();i++){
            if(visited.find(i)==visited.end()){
                stack<int> dfs;

                

                dfs.push(i);
                rec_stack[i]=true;
                while(!dfs.empty()){
                    int curr = dfs.top();
                    
                    if(visited.find(curr)!=visited.end()){
                        dfs.pop();
                        rec_stack[curr]=false;
                    }else{
                        visited.insert(curr);

                        for(auto neigh : connections[curr]){
                            if(rec_stack[neigh] && visited.find(neigh)!=visited.end()){
                                return true;
                            }
                            if(visited.find(neigh)==visited.end()){
                                dfs.push(neigh);
                                rec_stack[neigh]=true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};

int main(){
    vector<vector<int>>connections = {{1, 2, 3}, {2, 3}, {3}, {}};
    // vector<vector<int>>connections = {{1}, {2}, {3,4},{4} ,{0}};
    // vector<vector<int>>connections = {{1,4,3}, {}, {1,4,3},{1} ,{3}};

    CycleDetection detector;
    cout<<detector.hasCycleDFS(connections)<<endl;
    return 0;
}