package org.algorithm.problems

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

class `0182_n_queens_test` {

    @Test
    fun nEqualToFour(){
        val result = listOf<List<String>>(listOf(".Q..","...Q","Q...","..Q."), listOf("..Q.","Q...","...Q",".Q.."))
        val solution = `0182_n_queens`()
        assertEquals(solution.solveNQueens(4),result)
    }
}