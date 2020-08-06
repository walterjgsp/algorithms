package org.algorithm.structures

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.Test

class QueueTest {

    private lateinit var queue: Queue<Int>

    @BeforeEach
    fun init() {
        queue = Queue()
    }

    @Test
    fun testPush() {
        queue.push(1)
        queue.push(2)
        queue.push(3)
        assertEquals(3, queue.size)
        var value = 1
        while (!queue.empty()) {
            val top = queue.peek()
            queue.pop()
            assertEquals(value, top)
            value += 1
        }
    }

    @Test
    fun testQueueEmpty() {
        assertEquals(true, queue.empty())
    }

    @Test
    fun testQueuePop() {
        queue.push(1)
        queue.push(2)
        assertEquals(2, queue.size)
        queue.pop()
        assertEquals(1, queue.size)
    }

    @Test
    fun testQueueSize() {
        queue.push(1)
        queue.push(2)
        assertEquals(2, queue.size)
        queue.pop()
        assertEquals(1, queue.size)
        queue.push(2)
        queue.push(3)
        assertEquals(3, queue.size)
    }

    @Test
    fun testQueuePeek() {
        queue.push(1)
        assertEquals(1, queue.peek())
        queue.push(2)
        assertEquals(1, queue.peek())
        queue.pop()
        assertEquals(2, queue.peek())
    }

    @Test
    fun testPrintQueue() {
        queue.push(1)
        queue.push(2)
        assertEquals("1 2 ", queue.toString())
    }
}