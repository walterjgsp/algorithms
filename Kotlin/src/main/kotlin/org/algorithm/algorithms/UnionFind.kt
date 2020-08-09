package org.algorithm.algorithms

class UnionFind(val size: Int) {
    private val parents = Array<Pair<Int, Int>>(size) { index -> Pair(index, 0) }

    fun find(x: Int): Pair<Int, Int> {
        if (parents[x].first != x)
            parents[x] = find(parents[x].first)
        return parents[x]
    }

    fun union(x: Int, y: Int) {
        val xParent = find(x)
        val yParent = find(y)

        when {
            xParent.second < yParent.second -> {
                parents[x] = Pair(yParent.first, xParent.second)
            }
            xParent.second > yParent.second -> {
                parents[y] = Pair(xParent.first, yParent.second)
            }
            else -> {
                parents[y] = Pair(xParent.first, yParent.second)
                parents[x] = Pair(xParent.first, xParent.second + 1)
            }
        }
    }
}