#ifndef SEAT_RESERVATION_MANAGER_HPP_INCLUDED
#define SEAT_RESERVATION_MANAGER_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class SeatManager {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    SeatManager(int n);
    
    int reserve();
    
    void unreserve(int seatNumber);
};


#include "0188_seat_reservation_manager.cpp"

#endif
