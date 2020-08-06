package org.algorithm.algorithms

class UnionFind(val size: Int) {
    val parents = Array(size) { index -> index }

    fun find(x: Int): Int {
        return if (parents[x] == x) x else find(parents[x])
    }

    fun union(x: Int, y: Int) {
        val xparent = find(x)
        val yparent = find(y)

        if (xparent != yparent) {
            parents[x] = yparent
        }
    }
}