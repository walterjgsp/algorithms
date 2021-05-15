#include "../../problems/0188_seat_reservation_manager.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Seat Reservation Manager" ) {
    SeatManager *manager = new SeatManager(5);

    REQUIRE(manager->reserve() == 1);
    REQUIRE(manager->reserve() == 2);
    manager->unreserve(2);
    REQUIRE(manager->reserve() == 2);
    REQUIRE(manager->reserve() == 3);
    REQUIRE(manager->reserve() == 4);
    REQUIRE(manager->reserve() == 5);
    manager->unreserve(5);
}
