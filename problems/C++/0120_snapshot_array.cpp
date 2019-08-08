#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
private:
    unordered_map<int, map<int, int>> memo;
    int curr_snap = 0;

public:
    SnapshotArray(int length) {
        curr_snap = 0;
    }
    
    void set(int index, int val) {
        memo[index][curr_snap] = val;
    }
    
    int snap() {
        return curr_snap++;
    }
    
    int get(int index, int snap_id) {
        auto it = memo[index].upper_bound(snap_id);
        return it == memo[index].begin() ? 0 : prev(it)->second;
    }
};

void test2(){
    SnapshotArray snap_array(1);
    snap_array.snap();
    snap_array.snap();
    snap_array.set(0,4);
    snap_array.snap();
    cout<<snap_array.get(0,1)<<endl;
    snap_array.set(0,12);
    cout<<snap_array.get(0,1)<<endl;
    snap_array.snap();
    cout<<snap_array.get(0,3)<<endl;
}

void test3(){
    SnapshotArray snap_array(3);
    snap_array.set(1,3);
    snap_array.set(1,8);
    snap_array.snap();
    cout<<snap_array.get(1,0)<<endl;
    snap_array.set(2,5);
    cout<<snap_array.get(2,0)<<endl;
    snap_array.snap();
    snap_array.snap();
    snap_array.set(0,6);
    snap_array.set(0,12);
    cout<<snap_array.get(0,1)<<endl;
    snap_array.snap();
    snap_array.set(2,18);
    snap_array.set(2,20);
    snap_array.set(0,1);
    cout<<snap_array.get(2,1)<<endl;
    snap_array.snap();
    cout<<snap_array.get(2,2)<<endl;
}

unordered_map<int, map<int, int>> a;
int cur_snap = 0;
int snap() { return cur_snap++; }
void set(int index, int val) { 
  a[index][cur_snap] = val; 
}
int get(int index, int snap_id) {
  auto it = a[index].upper_bound(snap_id);
  return it == begin(a[index]) ? 0 : prev(it)->second;
}

int main(){
    test2();

    return 0;
}