//Problem Statement
// Koko loves to eat bananas.
// There are N piles of bananas, the i-th pile has piles[i] bananas.
// The guards have gone and will come back in H hours.
//
// Koko can decide her bananas-per-hour eating speed of K.
// Each hour, she chooses some pile of bananas, and eats K bananas from that pile.
// If the pile has less than K bananas, she eats all of them instead, and won't
// eat any more bananas during this hour.
//
// Koko likes to eat slowly, but still wants to finish eating all the bananas before
// the guards come back.
//
// Return the minimum integer K such that she can eat all the bananas within H hours.

class Solution {

    private fun hoursToEat(piles:IntArray, eatSpeed:Int): Int{
        var hours:Int = 0;

        for(pile in piles){
            hours+=pile/eatSpeed;
            if(pile%eatSpeed>0){
                hours++;
            }
        }

        return hours;
    }

    fun minEatingSpeed(piles: IntArray, H: Int): Int {
        var minBananas:Int = 1;
        var maxBananas:Int = 0;

        for(pile in piles){
            maxBananas = maxOf(maxBananas,pile);
        }

        while(minBananas<maxBananas){
            var midBananas:Int = minBananas+(maxBananas-minBananas)/2;

            if(hoursToEat(piles,midBananas)<=H){
                maxBananas = midBananas;
            }else{
                minBananas = midBananas + 1;
            }
        }

        return minBananas;
    }
}

fun main(args:Array<String>){
  var piles:IntArray = intArrayOf(30,11,23,4,20);
  var H:Int = 6;
  var sol:Solution = Solution();

  println(sol.minEatingSpeed(piles,H));
}
