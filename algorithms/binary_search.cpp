//Simple binary search in a sorted list.
// Complexity O(logn)

#include <bits/stdc++.h>

using namespace std;

class BinarySearch{
public:
   int search(const vector<int> &arr, int target){
     int start = 0,end=arr.size()-1;

     while(start<=end){
       int mid = start+(end-start)/2;

       if(arr[mid]==target)
        return mid;
       else if(arr[mid]<target)
        start = mid + 1;
       else
        end = mid -1;
     }

     return -1;
   }
};

int main(){
  vector<int> arr = {1,2,3,4,6,9,13,14,17,25,27};
  BinarySearch binarySearch;

  cout<<binarySearch.search(arr,6)<<endl;

  return 0;
}
