//Problem Statement

// Design a system that manages the reservation state of n seats that are numbered from 1 to n.

// Implement the SeatManager class:

// * SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
// * int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
// * void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.

#include "0188_seat_reservation_manager.hpp"
#include <bits/stdc++.h>

using namespace std;

SeatManager:SeatManager(int n){
    for(int i=1;i<=n;i++){
        pq.push(i);
    }
}

int SeatManager::reserve() {
    int top = pq.top();
    pq.pop();
    return top;
}

void SeatManager::unreserve(int seatNumber) {
    pq.push(seatNumber);
}