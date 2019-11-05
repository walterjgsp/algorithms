// Problem Statement
// We are given hours, a list of the number of hours worked per day for a given employee.

// A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

// A well-performing interval is an interval of days for which the number of tiring days is strictly larger than
// the number of non-tiring days.

// Return the length of the longest well-performing interval.
class Solution {
    fun longestWPI(hours: IntArray): Int {
        var sum : Int = 0;
        var result : Int = 0;
        val memo = hashMapOf<Int,Int>();
        
        for(i in hours.indices){
            if(hours[i]>8){
                sum++;
            }else{
                sum--;
            }
            
            if(sum>0){
                result = i+1;
            }else{
                memo[sum-1]?.let{
                    result = maxOf(result,i-it);                    
                }
            }
            
            if(!memo.contains(sum)){
                memo[sum] = i;
            }
        }
        
        return result;
    }
}

fun main(args: Array<String>) {
    val sol = Solution();
    val hours = intArrayOf(9,9,6,0,6,6,9);
    println(sol.longestWPI(hours));
}