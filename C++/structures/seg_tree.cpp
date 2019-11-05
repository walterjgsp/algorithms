#include <bits/stdc++.h>

using namespace std;

class Segtree{
private:
  vector<int> tree;
  int end_arr;

  int queryHelper(int treeIndex, int start, int end, const int &lower, const int &upper){
    if(start>upper || end<lower)
      return 0;

    if(lower<=start && end<=upper)
      return tree[treeIndex];

    int left,right,mid = start+(end-start)/2;

    left = queryHelper(2*treeIndex+1,start,mid,lower,upper);
    right = queryHelper(2*treeIndex+2,mid+1,end,lower,upper);

    return left+right;
  }

  int updateHelper(int treeIndex,int start, int end, const int &lower, const int &upper, const int &val){
    if(start>upper || end<lower)
      return tree[treeIndex];

    if(start==end){
      tree[treeIndex]+=val;
    }else{
      int left, right, mid = start+(end-start)/2;

      left = updateHelper(2*treeIndex+1,start,mid,lower,upper,val);
      right = updateHelper(2*treeIndex+2,mid+1,end,lower,upper,val);

      tree[treeIndex]=left+right;
    }

    return tree[treeIndex];
  }

public:
  Segtree(vector<int> arr){
    tree = vector<int> (arr.size()*4,0);
    end_arr = arr.size()-1;
    createTree(arr,0,0,end_arr);
  }

  void printTree(){
    for(auto val:tree){
      cout<<val<<" ";
    }
    cout<<endl;
  }

  int createTree(const vector <int> arr,int treeIndex,int start, int end){
    if(start == end){
      tree[treeIndex]=arr[start];
    }else{
      int mid = start+(end-start)/2;
      tree[treeIndex]=createTree(arr,2*treeIndex+1,start,mid)+createTree(arr,2*treeIndex+2,mid+1,end);
    }

    return tree[treeIndex];
  }

  int queryRange(int lower,int upper){
      return queryHelper(0,0,end_arr,lower,upper);
  }

  int updateRange(int lower, int upper, int val){
      return updateHelper(0,0,end_arr,lower,upper,val);
  }
};

int main(){
  vector<int> array = {2,3,4,8,9};
  Segtree seg_tree(array);

  seg_tree.printTree();
  cout<<seg_tree.queryRange(2,3)<<endl;
  seg_tree.updateRange(2,3,1);
  seg_tree.printTree();
  cout<<seg_tree.queryRange(2,3)<<endl;

  return 0;
}
