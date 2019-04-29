// Problem Statement
// We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever.
// For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed)
// travels in the sequence 1->5->7->1->5->7->1->... forever.
//
// We start at bus stop S (initially not on a bus), and we want to go to bus stop T.
// Travelling by buses only, what is the least number of buses we must take to reach
// our destination? Return -1 if it is not possible.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,vector<int>> station_buses;

        for(int i=0;i<routes.size();i++){
            for(auto station: routes[i]){
                station_buses[station].push_back(i);
            }
        }

        unordered_set<int> used_bus, visited_station;
        queue<int> bfs;
        int count = 0;

        bfs.push(S);

        while(!bfs.empty()){
            int tam = bfs.size();
            for(int i=0;i<tam;i++){
                int actual = bfs.front();
                bfs.pop();
                if(actual == T)
                    return count;

                if(visited_station.find(actual)==visited_station.end()){
                    visited_station.insert(actual);

                    for(auto bus : station_buses[actual]){
                        if(used_bus.find(bus)==used_bus.end()){
                            used_bus.insert(bus);
                            for(auto station : routes[bus]){
                                if(visited_station.find(station)==visited_station.end()){
                                    bfs.push(station);
                                }
                            }
                        }
                    }
                }
            }
            count++;
        }

        return -1;
    }
};

int main(){
  vector<vector<int>> routes = {{1,2,7},{3,6,7},{1,5,8},{2,4,6}};
  Solution sol;
  cout<<sol.numBusesToDestination(routes,5,6)<<endl;
  return 0;
}
