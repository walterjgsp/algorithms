// Problem Statement
// Design a class to find the kth largest element in a stream.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Your KthLargest class will have a constructor which accepts an integer k and an
// integer array nums, which contains initial elements from the stream.
// For each call to the method KthLargest.add, return the element representing the
// kth largest element in the stream.
#include <bits/stdc++.h>

using namespace std;

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int max_size = 0;
public:
    KthLargest(int k, vector<int> nums) {
        max_size = k;
        for(auto num : nums){
            add(num);
        }

    }

    int add(int val) {
        pq.push(val);
        if(pq.size()>max_size)
            pq.pop();

        return pq.top();
    }
};

int main(){
  vector<int> nums = {4,5,8,2};
  KthLargest kth(3,nums);
  cout<<kth.add(3)<<endl;
  cout<<kth.add(5)<<endl;
  cout<<kth.add(10)<<endl;
  cout<<kth.add(9)<<endl;
  cout<<kth.add(4)<<endl;

  return 0;
}
