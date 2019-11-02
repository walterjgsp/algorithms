//Problem Statement
//You're given strings J representing the types of stones that are jewels,
//Yand S representing the stones you have.  Each character in S is a type of
//Ystone you have.  You want to know how many of the stones you have are also jewels.
/*
The letters in J are guaranteed distinct, and all characters in J and S are
letters. Letters are case sensitive, so "a" is considered a different type of stone from "A". */

class Solution constructor(){
    fun numJewelsInStones(J: String, S: String): Int {
        val counter:IntArray = IntArray(256) { i->0 };
        var result:Int = 0;

        for(jewels in J){
            counter[jewels.toInt()]++;
        }

        for(stones in S){
            if(counter[stones.toInt()]>0){
                result++;
            }
        }

        return result;
    }
}

fun main(args:Array<String>){
  var j:String = "aA";
  var s:String =  "aAAbbbb";
  val sol:Solution = Solution();

  println(sol.numJewelsInStones(j,s));
}
