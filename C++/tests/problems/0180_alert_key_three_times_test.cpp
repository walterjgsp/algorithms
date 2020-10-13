#include "../../problems/0180_alert_key_three_times.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Alert Using Same Key-Card Three or More Times in a One Hour Period" ) {
    Solution sol;

    vector<string> name1 = {"daniel","daniel","daniel","luis","luis","luis","luis"};
    vector<string> time1 = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    vector<string> result1 = {"daniel"};
    REQUIRE(areVectorsEqual(sol.alertNames(name1,time1),result1));

    vector<string> name2 = {"alice","alice","alice","bob","bob","bob","bob"};
    vector<string> time2 = {"12:01","12:00","18:00","21:00","21:20","21:30","23:00"};
    vector<string> result2 = {"bob"};
    REQUIRE(areVectorsEqual(sol.alertNames(name2,time2),result2));

    vector<string> name3 = {"john","john","john"};
    vector<string> time3 = {"23:58","23:59","00:01"};
    vector<string> result3 = {};
    REQUIRE(areVectorsEqual(sol.alertNames(name3,time3),result3));

    vector<string> name4 = {"leslie","leslie","leslie","clare","clare","clare","clare"};
    vector<string> time4 = {"13:00","13:20","14:00","18:00","18:51","19:30","19:49"};
    vector<string> result4 = {"clare","leslie"};
    REQUIRE(areVectorsEqual(sol.alertNames(name4,time4),result4));
}