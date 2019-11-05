// Problem Statement
//
// N number of areas are given.
// The ith area has K number of collects.
// You have to allocate areas to M number of workers so that maximum number of collects
// alloted to a worker is minimum. A area will be allocated to exactly one worker.
// Each worker has to be allocated at least one area. Allotment should be in
// contiguous order, for example: A worker cannot be allocated area 1 and area 3, skipping area 2.
//
// Example:
//
// P : [12, 34, 67, 90]
// M : 2
//
// Output : 113

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
  int get_workers_needed(const vector<int> &areas,int &max_collects){
      int workers_needed = 1,actual_collects = areas[0];

      for(int i=1;i<areas.size();i++){
        actual_collects+=areas[i];
        if(actual_collects>max_collects){
          workers_needed++;
          actual_collects=areas[i];
        }
      }

      return workers_needed;
    }

  int minimum_collects(vector<int> areas, int workers){
    int max_collects=0,min_collects=INT_MIN;

    for(int collects : areas){
      max_collects+=collects;
      min_collects= max(min_collects,collects);
    }

    while(min_collects<max_collects){
      int mid_collects = min_collects+(max_collects-min_collects)/2;
      int quant_workers = get_workers_needed(areas,mid_collects);

      // If the number of workers necessary to execute all the max_collects
      // with the value that i choose is smaller than the minimum possible
      // we set the maximum of collects to a smaller value because it means
      // that some worker is doing more work than necessary otherwise,
      // somebody is not working enough.
      if(quant_workers<=workers){
        max_collects=mid_collects;
      }else{
        min_collects=mid_collects+1;
      }
    }

    return min_collects;
  }
};

int main(){
  vector<int> areas = { 13, 21, 12, 24, 8 };
  int workers = 3;
  Solution sol;

  cout<<sol.minimum_collects(areas,workers)<<endl;

  return 0;
}
