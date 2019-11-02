// Problem Statement
// Given two strings S and T, determine if they are both one edit distance apart.
class Solution{

    fun isOneEditDistance(s1 : String, s2 : String) : Boolean{
        var diff_count = 0
        var i = 0
        var j = 0

        while(i<s1.length && j<s2.length){
            if(s1[i]!=s2[j]){
                if(diff_count>1){
                    return false
                }

                if(s1.length == s2.length){
                    i++
                    j++
                }else if(s1.length<s2.length){
                    j++
                }else{
                    i++
                }

                diff_count++
            }else{
                i++
                j++
            }
        }

        if(i<s1.length || j<s2.length){
            diff_count++
        }

        return diff_count == 1
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    println(sol.isOneEditDistance("geek","geeks"))

}