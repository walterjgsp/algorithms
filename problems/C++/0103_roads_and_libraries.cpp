// Problem Statement
// The Ruler of HackerLand believes that every citizen of the country should 
// have access to a library. Unfortunately, HackerLand was hit by a tornado that 
// destroyed all of its libraries and obstructed its roads!
// As you are the greatest programmer of HackerLand, the ruler wants your help to 
// repair the roads and build some new libraries efficiently.

// HackerLand has n cities numbered from 1 to n . The cities are connected by m bidirectional 
// roads. A citizen has access to a library if:

// Their city contains a library.
// They can travel by road from their city to a city containing a library.

// Complete the function roadsAndLibraries to return the minimal cost of providing libraries to all, as an integer.
#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    vector<pair<int,int>> parents;

    int find(int x){
        if(x==parents[x].first)
            return x;
        return find(parents[x].first);
    }

    void Union(const int &x, const int &y){
        int xparent = find(x);
        int yparent = find(y);

        if(yparent!=xparent){
            if(parents[yparent].second>parents[xparent].second){
                parents[xparent].first = yparent;
                parents[yparent].second += parents[xparent].second;
            }else{
                parents[yparent].first = xparent;
                parents[xparent].second += parents[yparent].second;
            }
        }
    }

    map<int,int> getSets(){
        map<int,int> sets;
        for(auto x : parents){
            int xparent = find(x.first);
            sets[xparent]=0;
        }

        for(auto it : sets){
            sets[it.first] = parents[it.first].second;
        }

        return sets;
    }

    void initializeParents(const int &n){
        parents = vector<pair<int,int>>(n);
        for(int i=0;i<parents.size();i++){
            parents[i] = {i,1};
        }
    }
public:
    long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
        if(c_lib<=c_road){
            return c_lib *n;
        }

        long result = 0;
        initializeParents(n);
        for(auto road : cities){
            Union(road[0]-1,road[1]-1);
        }
        auto reform = getSets();
        for(auto it : reform){
            result += c_road*(it.second-1);
        }
        result+=(reform.size()*c_lib);

        return result;
    }
};

int main(){
    int cities = 7,cost_road = 2, cost_lib = 3;
    vector<vector<int>> roads = {{1,3},{1,7},{4,5},{1,2},{2,3},{5,6}};
    Solution sol;
    cout<<sol.roadsAndLibraries(cities,cost_lib,cost_road,roads)<<endl;
    return 0;
}