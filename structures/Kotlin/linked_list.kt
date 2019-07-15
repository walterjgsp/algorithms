class LinkedList<T> {
    private data class Node<T>(
        val value : T,
        var next: Node<T>? = null
    )

    private var front:Node<T>? = null
    private var back:Node<T>? = null
    private var capacity:Int = 0

    fun pushFront(value : T){
        val newNode = Node<T>(value = value)
        if(back==null){
            back = newNode
        }

        newNode.next = front
        front = newNode
    }

    fun pushBack(value : T){
        val newNode = Node<T>(value = value)
        if(front == null){
            front = newNode
        }

        back?.next = newNode
        back = newNode
    }

    fun printList(){
        var iterator: Node<T>? = front
        while(iterator!=null){
            print("${iterator.value} ")
            iterator = iterator.next
        }
        println()
    }
}

fun main(args: Array<String>) {
    val list =  LinkedList<Int>()
    list.pushFront(3)
    list.pushFront(4)
    list.pushBack(1)
    list.printList()
}