package org.algorithm.structures

class LRUCache(val capacity : Int){
    private data class Node(val key:Int ,var value:Int, var next:Node? = null, var prev:Node? = null)

    private var head: Node? = null
    private var tail: Node? = null
    private var size: Int = 0

    private val mapping = mutableMapOf<Int,Node>()

    private fun pushFront(key:Int, value:Int){
        val it = Node(key,value)
        if(head!=null){
            it.next = head
            head!!.prev = it
        }else{
            tail = it
        }

        size++
        head = it
    }

    private fun removeNode(node:Node){
        var it:Node? = node
        if(it?.prev==null){
            it = it?.next
            it?.prev = null
            head?.next = null
            head = it
            if(it==null)
                tail = head
        }else if(it.next==null){
            it = it?.prev
            it?.next = null
            tail?.prev = null
            tail = it
            if(it==null)
                head = tail
        }else{
            it.prev?.next = it.next
            it.next?.prev = it.prev
            it.next = null
            it.prev = null
        }
        size--
    }

    fun get(key: Int): Int {
        var result:Int = -1
        if(mapping.contains(key)){
            var node = mapping.get(key)
            result = node!!.value
            put(key,result)
        }
        return result
    }

    fun put(key: Int, value: Int) {
        if(mapping.contains(key)){
            var node = mapping.get(key)
            mapping.remove(key)
            removeNode(node!!)
        }else if(size>=capacity){
            var node = tail!!
            mapping.remove(node.key)
            removeNode(node)
        }

        pushFront(key,value)
        mapping.put(key,head!!)   
    }

    fun printCache(){
        print("List: ")
        var it = head
        while(it!=null){
            print(it.key.toString()+"->"+it.value.toString()+" ")
            it = it?.next
        }
        println()
    }    
}

//fun main(args: Array<String>) {
//    val lru = LRUCache(2)
//    lru.put(2,1)
//    lru.put(1,1)
//    lru.printCache()
//    println(lru.get(2))
//    lru.printCache()
//    lru.put(4,1)
//    lru.printCache()
//    println(lru.get(1))
//    lru.printCache()
//    println(lru.get(2))
//}