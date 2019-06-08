#include <bits/stdc++.h>

using namespace std;

class GraphUndirected{
private:
    vector<vector<int>> graph;
    int capacity;

public:
    GraphUndirected(int vertexes){
        graph = vector<vector<int>>(vertexes);
        capacity = vertexes;
    }

    void addEdge(const int &from, const int &to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> getNeighbors(const int&vertex){
        return graph[vertex];
    }

    void printGraph(){
        for(int i=0;i<graph.size();i++){
            cout<<i<<": ";
            for(auto neighbor : graph[i]){
                cout<<neighbor<<"-> ";
            }
            cout<<"End"<<endl;
        }
    }

    int size(){
        return capacity;
    }
};

class FindBridges{
public:
    vector<pair<int,int>> findBridges(GraphUndirected &graph){
        vector<bool> visited(graph.size(),false);
        vector<int> enterTime(graph.size(),-1), minEnter(graph.size()-1);
        vector<pair<int,int>> result;
        int time = 0;

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
                    result.push_back({parent,curr});
                }
            }else{
                visited[curr]=true;
                enterTime[curr] = minEnter[curr] = time++;
                for(auto to : graph.getNeighbors(curr)){
                    if(to==parent)
                        continue;
                    else if(visited[to])
                        minEnter[curr] = min(minEnter[curr],minEnter[to]);
                    else{
                        dfs.push({to,curr});
                    }
                }
            }
        }

        return result;
    }
};

void printBridges(const vector<pair<int,int>> &vec){
    for(auto bridge : vec){
        cout<<"("<<bridge.first<<","<<bridge.second<<") ";
    }
    cout<<endl;
}

int main(){
    GraphUndirected graph(6);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(0,3);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.printGraph();
    cout<<"Bridges: "<<endl;
    auto bridges = FindBridges().findBridges(graph);
    printBridges(bridges);

    return 0;
}