// Problem Statement
// One way to serialize a binary tree is to use pre-order traversal.
// When we encounter a non-null node, we record the node's value.
// If it is a null node, we record using a sentinel value such as #.
//
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string
// "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
// Given a string of comma separated values, verify whether it is a correct
// preorder traversal serialization of a binary tree.
// Find an algorithm without reconstructing the tree.
//
// Each comma separated value in the string must be either an integer or a
// character '#' representing null pointer.
//
// You may assume that the input format is always valid, for example it could
// never contain two consecutive commas such as "1,,3".
//
// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> helper;

        stringstream ss(preorder);
        string temp;

        while(getline(ss,temp,',')){
            if(temp!="#"){
                helper.push_back(temp);
            }else{
                helper.push_back(temp);
                int index = helper.size();

                while(!helper.empty() && index-2>=0 &&
                      helper[index-1]=="#" && helper[index-2]=="#"){

                    if(index-3<0)
                        return false;

                    if(helper[index-3]=="#")
                        return false;

                    helper.pop_back();
                    helper.pop_back();
                    helper.pop_back();
                    helper.push_back("#");

                    index = helper.size();
                }
            }
        }

        return (helper.size() ==1 && helper[0]=="#");
    }
};

int main(){
  string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  string preorder2 = "1,#";
  Solution sol;
  cout<<sol.isValidSerialization(preorder)<<endl;
  cout<<sol.isValidSerialization(preorder2)<<endl;
  return 0;
}
