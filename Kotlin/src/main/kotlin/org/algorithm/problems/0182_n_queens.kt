package org.algorithm.problems

import java.lang.StringBuilder

class `0182_n_queens` {

    private val result = mutableListOf<List<String>>()

    private fun checkRDiagonal(board: List<StringBuilder>, row: Int, column: Int): Boolean {
        var i = row
        var j = column
        while (i >= 0 && j < board.size) {
            if (board[i][j] == 'Q')
                return false
            i--
            j++
        }
        return true
    }

    private fun checkLDiagonal(board: List<StringBuilder>, row: Int, column: Int): Boolean {
        var i = row
        var j = column
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false
            i--
            j--
        }
        return true
    }

    private fun checkColumn(board: List<StringBuilder>, row: Int, column: Int): Boolean {
        for (index in row downTo 0) {
            if (board[index][column] == 'Q')
                return false
        }
        return true
    }


    private fun placeQueen(board: MutableList<StringBuilder>, row: Int) {
        if (row >= board.size) {
            result.add(board.map { it.toString() })
            return
        }

        for (i in board.indices) {
            if (checkColumn(board, row, i) &&
                    checkLDiagonal(board, row, i) &&
                    checkRDiagonal(board, row, i)) {
                board[row][i] = 'Q'
                placeQueen(board, row + 1)
                board[row][i] = '.'
            }
        }
    }

    fun solveNQueens(n: Int): List<List<String>> {
        val board = MutableList<StringBuilder>(n){StringBuilder(String(CharArray(n){'.'}))}
        placeQueen(board,0)
        return result
    }
}