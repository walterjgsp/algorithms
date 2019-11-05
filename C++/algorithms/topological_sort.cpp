#include<bits/stdc++.h>

using namespace std;

class TopologicalSort{
public:
    vector<int> execOrder(vector<pair<int,int>> dependencies, const int &vertexCount){
        vector<vector<int>> graph(vertexCount);

        for(auto dep : dependencies){
            graph[dep.first].push_back(dep.second);
        }

        vector<int> result, disc(vertexCount,INT_MAX);
        unordered_set<int> processed;
        int timestamp;

        for(int i=0;i<vertexCount;i++){
            if(processed.find(i)==processed.end()){
                stack<int> dfs;
                dfs.push(i);

                while(!dfs.empty()){
                    int curr = dfs.top();
                    auto neighboors = graph[curr];
                    if(processed.find(curr)!=processed.end()){
                        dfs.pop();
                        continue;
                    }

                    if(disc[curr]==INT_MAX){
                        disc[curr] = timestamp;
                        for(auto neigh : neighboors){
                            if(processed.find(neigh)!=processed.end()){
                                continue;
                            }else if(disc[neigh]!=INT_MAX){
                                return {};
                            }else{
                                dfs.push(neigh);
                            }
                        }
                        timestamp++;
                    }else{
                        for(auto neigh : neighboors){
                            if(processed.find(neigh)==processed.end()){
                                return {};
                            }
                        }
                        dfs.pop();
                        processed.insert(curr);
                        result.push_back(curr);
                    }
                }
            }
        }

        return result;
    }
};

void printVec(const vector<int> &vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<pair<int,int>> dependecies = {{0,1},{1,2},{2,4},{5,4},{3,4}};
    TopologicalSort tp;

    printVec(tp.execOrder(dependecies,6));

    return 0;
}