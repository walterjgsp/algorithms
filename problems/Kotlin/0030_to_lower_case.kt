// Problem Statement

// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
class Solution {
    fun toLowerCase(str: String): String {
        var result:String=""
        for(i in 0 until str.length){
            var letter = str[i]
            if(letter>='A' && letter<='Z'){
                letter = 'a'+(letter-'A')
            }
            result += letter
        }
        
        return result
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val str = "LOVELY"
    println(sol.toLowerCase(str))
}