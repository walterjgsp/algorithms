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

    //TODO query in bst 
    //TODO find minimum on bst
    //TODO remove element from bst
}

fun main(args: Array<String>) {
    val bst  = BinarySearchTree()
    bst.insert(4)
    bst.insert(2)
    bst.printInorder()
}