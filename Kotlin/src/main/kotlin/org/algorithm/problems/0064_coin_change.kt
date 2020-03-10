//Problem statement
// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
package org.algorithm.problems

class `0064_coin_change`{
    fun coinChange(coins: IntArray, amount: Int): Int {
        coins.sort()
        var dp:IntArray = IntArray(amount+1) {i->-1}
        dp[0]=0;

        for(value in 1..amount){

            var index:Int = 0
            var minQuantChange:Int = -1
            while(index<coins.size && coins[index]<=value){
                if(dp[value-coins[index]]!=-1){
                    if(minQuantChange==-1)
                        minQuantChange = dp[value-coins[index]]+1
                    else
                        minQuantChange = minOf(minQuantChange,dp[value-coins[index]]+1)
                }
                index++
            }

            dp[value]=minQuantChange
        }

        return dp.last();
    }
}