package org.algorithm.shared

data class Edge(val from: Int, val to: Int, val weight: Int) : Comparable<Edge> {
    override fun compareTo(other: Edge): Int {
        return weight.compareTo(other.weight)
    }

    fun toTriple(): Triple<Int, Int, Int> {
        return Triple(weight, from, to)
    }

    override fun equals(other: Any?): Boolean {
        return if (other is Edge) {
            from == other.from && to == other.to && weight == other.weight
        } else {
            super.equals(other)
        }
    }

    override fun hashCode(): Int {
        var result = from
        result = 31 * result + to
        result = 31 * result + weight
        return result
    }
}