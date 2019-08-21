//Problem Statement
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maxAreaHistogram(const vector<int> &hist){
        stack<int> indices;
        int result = 0;

        for(int i=0;i<hist.size();i++){
            while(!indices.empty() && hist[indices.top()]>=hist[i]){
                int height = hist[indices.top()];
                indices.pop();

                int area = 0;
                if(indices.empty()){
                    area = height * i;
                }else{
                    area = height * (i-indices.top()-1);
                }

                result = max(result,area);
            }
        }

        while(!indices.empty()){
            int height = hist[indices.top()];
            indices.pop();

            int area = 0;
            if(indices.empty()){
                area = height * hist.size();
            }else{
                area = height * (hist.size()-indices.top()-1);
            }

            result = max(result,area);
        }

        return result;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        vector<vector<int>> hist(vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),0)));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    if(i>0){
                        hist[i][j] = hist[i-1][j]+1;
                    }else{
                        hist[i][j] = 1;
                    }
                }
            }
        }

        int result = 0;
        for(auto row : hist){
            int curr_max = maxAreaHistogram(row);
            result = max(result,curr_max);
        }

        return result;
    }
};

int main(){
    vector<vector<char>> matrix = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    Solution sol;
    cout<<sol.maximalRectangle(matrix)<<endl;
    return 0;
}