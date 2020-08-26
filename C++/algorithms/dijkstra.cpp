//Dijkstra is an algorithm for finding the shortest paths between nodes in a graph
//Time Complexity: O((V+E)logV)
//Space Complexity: O(V+E)

#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<vector<pair<int,int>>> graph;

public:
    Graph(int size){
        graph = vector<vector<pair<int,int>>>(size);
    }

    void addEdge(const int &from, const int &to, const int &weight){
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }

    vector<pair<int,int>> getChildren(const int &vertex){
        return graph[vertex];
    }

    void printGraph(){
        for(int i=0;i<graph.size();i++){
            cout<<i<<" : ";
            for(auto edge : graph[i]){
                cout<<"{"<<edge.first<<","<<edge.second<<"} ->";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int size(){
        return graph.size();
    }
};

class Dijkstra{
private:
    struct Edge{
        int from,to,weight;
        Edge(int _from, int _to, int _weight){
            from=_from;
            to=_to;
            weight=_weight;
        }
    };

    class edgeComparator{
        public:
        int operator()(const Edge &e1,Edge &e2){
            if(e1.weight==e2.weight){
                return e1.from<=e2.from;
            }
            return e1.weight>e2.weight;
        }
    };
    
public:
    vector<int> findMinPath(const int &start,Graph &graph){
        vector<int> min_path(graph.size(),INT_MAX);
        unordered_set<int> visited;

        priority_queue<Edge,vector<Edge>,edgeComparator> pq;

        pq.push(Edge(start,start,0));

        while(!pq.empty()){
            auto curr_edge = pq.top();
            pq.pop();

            min_path[curr_edge.to] = min(min_path[curr_edge.to],curr_edge.weight);
            visited.insert(curr_edge.to);
            for(auto children : graph.getChildren(curr_edge.to)){
                if(visited.count(children.first)==0){
                    pq.push(Edge(curr_edge.to,children.first,children.second+min_path[curr_edge.to]));
                }
            }
        }

        return min_path;
    }
};

int main(){

    Graph graph(9);
    graph.addEdge(0,1,4);
    graph.addEdge(0,7,8);
    graph.addEdge(1,7,11);
    graph.addEdge(1,2,8);
    graph.addEdge(2,8,2);
    graph.addEdge(2,3,7);
    graph.addEdge(2,5,4);
    graph.addEdge(3,5,14);
    graph.addEdge(3,4,9);
    graph.addEdge(4,5,10);
    graph.addEdge(5,6,2);
    graph.addEdge(6,7,1);
    graph.addEdge(6,8,6);
    graph.addEdge(7,8,7);
    graph.printGraph();

    auto min_path = Dijkstra().findMinPath(0,graph);

    for(auto v : min_path){
        cout<<v<<" ";
    }

    cout<<endl;

    return 0;
}