// Problem Statement

// Given a balanced parentheses string S, compute the score of the string based on
// the following rule:
//
// - () has score 1
// - AB has score A + B, where A and B are balanced parentheses strings.
// - (A) has score 2 * A, where A is a balanced parentheses string.

// Exemple: () = 1; (())=2; (()(())) = 6
import java.util.Stack

class Solution {
    fun scoreOfParentheses(S: String): Int {
        val values = Stack<Int>()
        val paren = Stack<Int>()
        
        for(c in S){
            if(c=='('){
                paren.push(1)
                if(values.size<paren.size){
                    values.push(0)
                }
            }else{
                paren.pop()
                val diff = values.size - paren.size
                if(diff == 1){
                    var curr = values.pop()
                    curr += 1
                    values.push(curr)
                }else if(diff == 2){
                    var curr = 2*values.pop()
                    curr += values.pop()
                    values.push(curr)
                }
            }
        }
        
        return if(values.empty()) 0 else values.peek()
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    println(sol.scoreOfParentheses("(()(()))"))
}