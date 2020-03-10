class Stack<T>{
    private data class Node<T>(
        val value: T,
        var next:Node<T>? = null
    )

    private var back: Node<T>? =null
    private var capacity:Int = 0

    fun push(value : T){
        val newNode = Node<T>(value)
        newNode.next = back
        back = newNode
    }

    fun size() = capacity

    fun pop(){
        back?.let{
            back = it.next
        }
    }

    fun top() = back?.value

    fun printStack(){
        var iterator: Node<T>? = back
        while(iterator!=null){
            print("${iterator.value} ")
            iterator = iterator.next
        }
    }
}

fun main(args: Array<String>) {
    val stack: Stack<Int> = Stack<Int>()
    stack.push(3)
    stack.push(2)
    stack.printStack()
    println("\nRemoving last")
    stack.pop()
    stack.printStack()
}