// Problem Statement
// Given an array equations of strings that represent relationships between variables,
// each string equations[i] has length 4 and takes one of two different forms: "a==b"
// or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that
// represent one-letter variable names.
//
// Return true if and only if it is possible to assign integers to variable names
// so as to satisfy all the given equations.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<string> inequations;
        map<char,set<char>> graph;

        for(auto eq : equations){
            if(eq[1]=='!'){
                inequations.push_back(eq);
            }else{
                graph[eq[0]].insert(eq[3]);
                graph[eq[3]].insert(eq[0]);
            }
        }

        for(auto inq : inequations){
            char start = inq[0], end = inq[3];
            if(start==end || canReach(graph,start,end))
                return false;
        }

        return true;
    }

    bool canReach(map<char,set<char>> &graph, const char &start, const char &end){
        stack<char> dfs;
        set<char> visited;

        dfs.push(start);

        while(!dfs.empty()){

            char actual_vertex = dfs.top();

            if(actual_vertex==end)
                return true;

            if(visited.find(actual_vertex)!=visited.end())
                dfs.pop();
            else{
                for(auto vertex : graph[actual_vertex]){
                    dfs.push(vertex);
                }
                visited.insert(actual_vertex);
            }
        }

        return false;
    }
};

int main(){
  vector<string> equations = {"a==b","b==c","a==c"};
  Solution sol;
  cout<<sol.equationsPossible(equations)<<endl;
  return 0;
}
