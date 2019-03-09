// Problem Statement
// Implement a MyCalendar class to store your events.
// A new event can be added if adding the event will not cause a double booking.
//
// Your class will have the method, book(int start, int end). Formally,
// this represents a booking on the half open interval [start, end),
// the range of real numbers x such that start <= x < end.
//
// A double booking happens when two events have some non-empty
// intersection (ie., there is some time that is common to both events.)
//
// For each call to the method MyCalendar.book, return true if the event can be
// added to the calendar successfully without causing a double booking.
// Otherwise, return false and do not add the event to the calendar.

#include <bits/stdc++.h>

using namespace std;

class MyCalendar{
private:
  struct Interval{
    int start,end;
    Interval(){};
    Interval(int s, int e){
      start = s;
      end = e;
    }
  };

  class EventTree{
  private:
    struct TreeNode{
      Interval interval;
      TreeNode *left,*right;
      TreeNode(Interval inter){
        interval = inter;
        left = NULL;
        right = NULL;
      }
    };
    TreeNode * root;
    
  public:
    EventTree(){
      root = NULL;
    }

    bool insert(Interval newInterval){
      if(!root){
        root = new TreeNode(newInterval);
        return true;
      }

      TreeNode *it = root;
      while(it){
        Interval actual = it->interval;

        if(newInterval.start < actual.start){
          if(newInterval.end>actual.start){
            return false;
          }

          if(it->left)
            it = it->left;
          else{
            it->left = new TreeNode(newInterval);
            break;
          }
        }else{
          if(newInterval.start<actual.end)
              return false;
          if(it->right)
              it = it->right;
          else{
              it->right = new TreeNode(newInterval);
              break;
          }
        }
      }
      return true;
    }
  };

  EventTree eventTree;

public:
  MyCalendar(){}

  bool book(int start, int end){
    Interval interval(start,end);
    return eventTree.insert(interval);
  }
};

int main(){
  MyCalendar myCalendar;
  vector<int> events = {10,20,15,25,20,30,5,10};
  for(int i=0;i<events.size();i+=2){
    if(myCalendar.book(events[i],events[i+1])){
      cout<<"("<<events[i]<<","<<events[i+1]<<") Booked"<<endl;
    }else{
      cout<<"Can't book"<<endl;
    }
  }
  return 0;
}
