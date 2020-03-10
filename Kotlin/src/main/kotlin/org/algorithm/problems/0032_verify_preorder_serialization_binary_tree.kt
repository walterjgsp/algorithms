// Problem Statement
// One way to serialize a binary tree is to use pre-order traversal.
// When we encounter a non-null node, we record the node's value.
// If it is a null node, we record using a sentinel value such as #.
//
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string
// "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
// Given a string of comma separated values, verify whether it is a correct
// preorder traversal serialization of a binary tree.
// Find an algorithm without reconstructing the tree.
//
// Each comma separated value in the string must be either an integer or a
// character '#' representing null pointer.
//
// You may assume that the input format is always valid, for example it could
// never contain two consecutive commas such as "1,,3".
//
// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true

import java.util.Stack

class Solution {    
    fun isValidSerialization(preorder: String): Boolean {
        val helper = Stack<Pair<String,Int>>()
        val splited = preorder.split(',')
        var index = 0
        
        while(index<splited.size){
            if(splited[index]=="#"){
                if(helper.isEmpty()){
                  if(index==0 && splited.size==1)
                    return true
                  else
                    return false
                }                 
                
                helper.incrementLast()
                while(!helper.isEmpty() && helper.peek().second==2){
                    helper.pop();
                    if(!helper.isEmpty()){
                        helper.incrementLast()
                    }
                }
            }else{
                helper.push(Pair(splited[index],0))
            }
            
            index+=1
            
            if(helper.empty()){
                break;
            }
        }
        
        return helper.isEmpty() && index == splited.size
    }
    
    private fun Stack<Pair<String,Int>>.incrementLast(){
        val last = this.pop()
        this.push(Pair<String,Int>(last.first,last.second+1))
    }
}

fun main(args: Array<String>) {
    val preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
    val sol = Solution()
    println(sol.isValidSerialization(preorder))
}