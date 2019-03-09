//Problem Statement

// Equations are given in the format A / B = k, where A and B are variables
// represented as strings, and k is a real number (floating point number).
// Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given a / b = 2.0, b / c = 3.0.
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double evaluate(map<string, map <string,double> > &graph, string start, string end){
        queue <pair<string,double>> bfs;
        set <string> visited;

        bfs.push(make_pair(start,1.0));

        while(!bfs.empty()){

            auto vertex = bfs.front();
            bfs.pop();

            if(visited.find(vertex.first)!=visited.end())
                continue;

            visited.insert(vertex.first);

            auto adj_vertex = graph[vertex.first];

            for(auto it:adj_vertex){
                double new_val = vertex.second*it.second;
                if(end == it.first)
                    return new_val;

                bfs.push(make_pair(it.first,new_val));
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map <string,double> >graph;
        vector<double> to_return;

        for(int i=0;i<equations.size();i++){
            string start = equations[i].first,end=equations[i].second;
            double val = values[i];

            graph[start][end]=val;
            graph[end][start]=1/val;
        }

        for(auto query:queries){
            string start = query.first,end=query.second;

            if(graph.find(start)==graph.end() || graph.find(end)==graph.end()){
                to_return.push_back(-1.0);
            }else if(start==end){
                to_return.push_back(1.0);
            }else{
                to_return.push_back(evaluate(graph,start,end));
            }
        }

        return to_return;
    }
};

template <class T>
void printVec(const vector<T> vec){
  cout<<"["<<vec[0];
  for(int i=1;i<vec.size();i++){
    cout<<","<<vec[i];
  }
  cout<<"]"<<endl;
}

int main(){
  vector<pair<string, string>> equations= {{"a","b"},{"b","c"},{"e","d"}},
    queries={ {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  vector<double> values ={2.0,3.0,5.0};
  Solution sol;
  printVec(sol.calcEquation(equations,values,queries));
  return 0;
}
