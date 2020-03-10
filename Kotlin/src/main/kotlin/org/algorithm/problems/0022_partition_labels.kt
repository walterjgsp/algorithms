package org.algorithm.problems

class `0022_partition_labels` {
    fun partitionLabels(S: String): List<Int> {
        val lettersIntervals = MutableList<Pair<Int,Int>>(26) { _ -> Pair(Int.MAX_VALUE,Int.MIN_VALUE)}
        val result = mutableListOf<Int>()

        for(i in 0 until S.length){
            val index = S[i]-'a'
            if(lettersIntervals[index].first == Int.MAX_VALUE){
                lettersIntervals[index] = Pair(i,i)
            }else{
                lettersIntervals[index] = Pair(lettersIntervals[index].first,i)
            }
        }

        val intervals = mutableListOf<Pair<Int,Int>>()
        val mergedIntervals = mutableListOf<Pair<Int,Int>>()

        for(inter in lettersIntervals){
            if(inter.first != Int.MAX_VALUE){
                intervals.add(inter)
            }
        }

        intervals.sortWith(Comparator{ p1: Pair<Int,Int>, p2: Pair<Int,Int> ->
            if(p1.first == p2.first) p1.second - p2.second
            else p1.first - p2.first
        })  

        var currInterval = intervals.first()

        for(i in 1 until intervals.size){
            val inter = intervals[i]
            if(currInterval.second>inter.first){
                val first = Math.min(currInterval.first,inter.first)
                val second = Math.max(currInterval.second,inter.second)
                currInterval = Pair(first,second)
            }else{
                mergedIntervals.add(currInterval)
                currInterval = inter
            }
        }

        mergedIntervals.add(currInterval)
        for(inter in mergedIntervals){
            result.add(inter.second - inter.first+1)
        }

        return result
    }
}