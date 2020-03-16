//Problem Statement
// Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.
//
// Person A will NOT friend request person B (B != A) if any of the following conditions are true:
//
// age[B] <= 0.5 * age[A] + 7
// age[B] > age[A]
// age[B] > 100 && age[A] < 100
// Otherwise, A will friend request B.
//
// Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
//
// How many total friend requests are made?
package org.algorithm.problems

class `0042_friends_of_appropriate_ages` {
    fun numFriendRequests(ages: IntArray): Int {
        val counter: IntArray = IntArray(121) { i -> 0 };
        var result: Int = 0;

        for (age in ages) {
            counter[age]++;
        }

        for (i in 1..counter.size - 1) {
            counter[i] += counter[i - 1];
        }

        for (age in ages) {
            result += maxOf(0, counter[age] - counter[age / 2 + 7] - 1);
        }

        return result;
    }
}