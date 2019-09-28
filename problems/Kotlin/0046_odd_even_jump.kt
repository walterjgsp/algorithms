
class BST{
    data class Node(
        var value: Int,
        var index: Int,
        var left: Node? = null,
        var right: Node? = null
    )

    private var root: Node? = null

    fun add(value : Int, index : Int){
        if(root==null){
            root = Node(value,index)
        }else{
            var it = root

            while(it!=null){
                if(it.value == value){
                    it.index = index
                    break
                }else if(it.value<value){
                    if(it.right==null){
                        it.right = Node(value,index)
                        break
                    }else{
                        it = it.right
                    }
                }else{
                    if(it.left==null){
                        it.left = Node(value,index)
                        break
                    }else{
                        it = it.left
                    }
                }
            }
        }
    }

    fun getMaxSmallest(value: Int): Int?{
        var it = root
        var curr: Node? = null
        while(it!=null){
            if(it.value<=value){
                curr = it
                it = it.right
            }else{
                it = it.left
            }
        }
        return curr?.index
    }

    fun getMinBiggest(value:Int) : Int?{
        var it = root
        var curr: Node? = null
        while(it!=null){
            if(it.value>=value){
                curr = it
                it = it.left
            }else{
                it = it.right
            }
        }
        return curr?.index
    }
}

class Solution {
    fun oddEvenJumps(A: IntArray): Int {
        val bst = BST()
        var result = 0
        val oddJump = IntArray(A.size){0}
        val evenJump = IntArray(A.size){0}

        oddJump[A.size-1] = 1
        evenJump[A.size-1] = 1
        bst.add(A[A.size-1],A.size-1)

        for(i in A.size-2 downTo 0){
            val indexOdd = bst.getMinBiggest(A[i])
            val indexEven = bst.getMaxSmallest(A[i])

            indexEven?.let{
                evenJump[i] = oddJump[indexEven] 
            }

            indexOdd?.let{
                oddJump[i] = evenJump[indexOdd]
            }
            bst.add(A[i],i)
        }

        for(jump in oddJump){
            result+=jump
        }

        return result
    }
}

fun main(args: Array<String>) {
    val arr = intArrayOf(10,13,12,14,15)
    val sol = Solution()
    println(sol.oddEvenJumps(arr))
}