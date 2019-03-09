// Problem Statement
// There are N students in a class. Some of them are friends, while some are not.
// Their friendship is transitive in nature. For example, if A is a direct friend of B,
// and B is a direct friend of C, then A is an indirect friend of C.
// And we defined a friend circle is a group of students who are direct or indirect friends.
//
// Given a N*N matrix M representing the friend relationship between students in the class.
// If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
//  And you have to output the total number of friend circles among all the students.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        set<int> visited;
        int circles = 0;

        for(int i=0;i<M.size();i++){
            if(visited.find(i)==visited.end()){

                stack<int> dfs;

                dfs.push(i);

                while(!dfs.empty()){
                    int friends = dfs.top();
                    dfs.pop();
                    if(visited.find(friends)==visited.end()){
                        for(int j=0;j<M[friends].size();j++){
                            if(M[friends][j]==1){
                                dfs.push(j);
                            }
                        }
                        visited.insert(friends);
                    }
                }

                circles++;
            }
        }

        return circles;
    }
};

int main(){
  vector<vector<int>> M ={{1,1,0},{1,1,0},{0,0,1}};
  Solution sol;

  cout<<sol.findCircleNum(M)<<endl;

  return 0;
}
