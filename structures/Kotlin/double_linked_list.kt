class DoubleLinkedList(){
    private data class Node(var prev:Node? = null,var next:Node?=null, var value: Int)

    private var head:Node? = null
    private var tail:Node? = null
    var size:Int = 0
        private set

    fun printList(){
        var it: Node? = head
        println("Lista:")
        while(it!=null){
            print(it.value.toString()+" ")
            it = it.next
        }
        println()
    }

    fun pushFront(value : Int){
        val newNode = Node(value=value)
        if(head==null){
            head = newNode
            tail = head
        }else{
            newNode.next = head
            head?.prev = newNode
            head = newNode
        }
        size++
    }

    fun popFront(){
        var it:Node? = head
        if(it!=null){
            size --
            it = it.next
            if(it==null)
                tail = it
        }

        head = it
    }

    fun pushBack(value : Int){
        val newNode = Node(value=value)
        if(tail!=null){
            tail?.next = newNode
            newNode?.prev = tail
            tail = newNode
        }else{
            head = newNode
            tail = head
        }
        size++
    }

    fun popBack(){
        var it:Node? = tail
        if(it!=null){
            size--
            it = it.prev
            if(it==null)
                head = it
        }

        tail = it
    }
}

fun main(args: Array<String>) {
    val dList = DoubleLinkedList()
    dList.printList()
    dList.pushFront(1)
    dList.printList()
    dList.pushFront(5)
    dList.pushFront(3)
    dList.printList()
    dList.popFront()
    dList.printList()
    dList.pushBack(6)
    dList.printList()
    println(dList.size)
    dList.popBack()
}