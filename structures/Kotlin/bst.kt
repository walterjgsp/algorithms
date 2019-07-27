class BinarySearchTree{

    private data class BNode(
        val value : Int,
        var left: BNode? = null,
        var right:BNode? = null
    )

    private var root :BNode? = null

    private fun insertHelper(value : Int, node: BNode?) : BNode{
        if(node==null){
            return BNode(value)
        }else{
            if(value <= node.value){
                node.left = insertHelper(value,node.left)
            } else{
                node.right = insertHelper(value,node.right)
            }
            return node
        }
    }

    private fun queryRecursive(value: Int, node: BNode?) : Boolean{
        if(node==null){
            return false;
        }else{
            if(value == node.value){
                return true;
            }else if(value<node.value){
                return queryRecursive(value,node.left)
            }else{
                return queryRecursive(value,node.right)
            }
        }
    }

    private fun inorderHelper(node : BNode?){
        if(node!=null){
            inorderHelper(node.left)
            print("${node.value} ")
            inorderHelper(node.right)
        }
    }

    fun printInorder(){
        inorderHelper(root)
        println()
    }

    fun insert(value: Int){
        root = insertHelper(value,root)
    }

    fun query(value : Int, recursive: Boolean = true) : Boolean{
        return queryRecursive(value,root)
    }

    fun findMinimum() : Int{
        var it : BNode? = root
        while(it?.left!=null){
            it = it.left
        }
        return it?.value ?: MIN_VALUE
    }

    //TODO remove element from bst
}

fun main(args: Array<String>) {
    val bst  = BinarySearchTree()
    bst.insert(4)
    bst.insert(2)
    bst.printInorder()
    println(bst.query(2))
}