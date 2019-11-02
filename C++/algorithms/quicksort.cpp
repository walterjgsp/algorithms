// Recursive quicksort to sort an array of int
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
#include <bits/stdc++.h>

using namespace std;

class Sorter{
private:
  int partition(vector<int> &vec, int start, int end){
    int pivot = vec[end], smaller = start;
    for(int j=smaller;j<end;j++){
      if(vec[j]<=pivot){
        swap(vec[j],vec[smaller]);
        smaller++;
      }
    }
    swap(vec[smaller],vec[end]);
    return smaller;
  }

  void quicksort(vector<int> &vec, int start, int end){
    if(start<end){
      int pivot_index = partition(vec,start,end);
      quicksort(vec,start,pivot_index-1);
      quicksort(vec,pivot_index+1,end);
    }
  }

public:
  vector<int> sort(vector<int> arr){
    quicksort(arr,0,arr.size()-1);
    return arr;
  }
};

void printVec(const vector<int> &arr){
  for(auto val : arr){
    cout<<val<<" ";
  }
  cout<<endl;
}

int main(){
  vector<int> arr = {-4,0,7,4,9,-5,-1,0,-7,-1};
  Sorter sorter;
  printVec(sorter.sort(arr));
  return 0;
}
