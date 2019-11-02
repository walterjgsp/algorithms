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
        capacity++
    }

    fun pushBack(value : T){
        val newNode = Node<T>(value = value)
        if(front == null){
            front = newNode
        }

        back?.next = newNode
        back = newNode
        capacity++
    }

    fun printList(){
        var iterator: Node<T>? = front
        while(iterator!=null){
            print("${iterator.value} ")
            iterator = iterator.next
        }
        println()
    }

    fun isEmpty() : Boolean {
        return capacity == 0
    }

    fun find(value : T): Boolean{
        var it: Node<T>? = front
        while(it!=null){
            if(it.value == value){
                return true
            }
            it = it.next
        }
        return false
    }
}

fun main(args: Array<String>) {
    val list =  LinkedList<Int>()
    list.pushFront(3)
    list.pushFront(4)
    list.pushBack(1)
    list.printList()
    println(list.find(2))
}