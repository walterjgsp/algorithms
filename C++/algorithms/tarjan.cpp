#include<bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<vector<int>> adjList;

public:
    Graph(int t_size){
        adjList = vector<vector<int>>(t_size);
    }

    void addEdge(const int &from, const int &to){
        adjList[from].push_back(to);
    }

    int getSize(){
        return adjList.size();
    }

    vector<int> getNeighbors(const int &vertex){
        return adjList[vertex];
    }
};

class Tarjan{
public:

    map<int,vector<int>> scc(Graph graph){
        vector<int> disc(graph.getSize(),INT_MAX);
        map<int,vector<int>> groups;
        int timestamp = 0;
        unordered_set<int> on_group;

        for(int i=0;i<disc.size();i++){
            if(on_group.find(i)==on_group.end()){
                stack<int> dfs;
                dfs.push(i);

                while(!dfs.empty()){
                    int curr = dfs.top();
                    auto neighbors = graph.getNeighbors(curr);

                    if(disc[curr]==INT_MAX){
                        disc[curr]=timestamp;
                        for(auto neigh : neighbors){
                            if(disc[neigh]==INT_MAX){
                                dfs.push(neigh);
                            }
                        }
                        timestamp++;
                    }else if(on_group.find(curr)!=on_group.end()){
                        dfs.pop();
                    }else{
                        int lower_neigh = disc[curr];
                        for(auto neigh : neighbors){
                            if(on_group.find(neigh)==on_group.end()){
                                lower_neigh = min(lower_neigh,disc[neigh]);
                            }
                        }
                        queue<int> not_discovered;
                        while(!dfs.empty()){
                            int top = dfs.top();
                            dfs.pop();
                            if(disc[top]==INT_MAX){
                                not_discovered.push(top);
                            }else {
                                on_group.insert(top);
                                if(disc[top]>lower_neigh){
                                    disc[top] = lower_neigh;
                                }else if(disc[top] == lower_neigh){
                                    break;
                                }
                            }
                        }

                        while(!not_discovered.empty()){
                            dfs.push(not_discovered.front());
                            not_discovered.pop();
                        }
                    }
                }
            }
        }

        for(int i=0;i<disc.size();i++){
            groups[disc[i]].push_back(i);
        }

        return groups;
    }
};

Graph test1(){
    Graph graph(8);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(2,5);
    graph.addEdge(3,0);
    graph.addEdge(3,2);
    graph.addEdge(4,7);
    graph.addEdge(5,4);
    graph.addEdge(5,7);
    graph.addEdge(6,4);
    graph.addEdge(7,6);  

    return graph;  
}

Graph test2(){
    Graph graph(7);

    graph.addEdge(1,0);
    graph.addEdge(1,2);
    graph.addEdge(2,4);
    graph.addEdge(3,1);
    graph.addEdge(3,2);
    graph.addEdge(3,5);
    graph.addEdge(4,3);
    graph.addEdge(4,6);
    

    return graph;  
}

void printGroups(const map<int,vector<int>> &groups){
    for(auto group : groups){
        cout<<group.first<<": ";
        for(auto ind : group.second){
            cout<<ind<<" , ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    auto graph = test2();
    Tarjan tarjan;
    printGroups(tarjan.scc(graph));
    return 0;
}