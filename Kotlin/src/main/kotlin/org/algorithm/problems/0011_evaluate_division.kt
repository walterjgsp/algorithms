//Problem Statement

// Equations are given in the format A / B = k, where A and B are variables
// represented as strings, and k is a real number (floating point number).
// Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given a / b = 2.0, b / c = 3.0.
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].
package org.algorithm.problems

import java.util.ArrayDeque;

class `0011_evaluate_division` {
    fun calcEquation(equations: Array<Array<String>>, values: DoubleArray, queries: Array<Array<String>>): DoubleArray {

        val graph = HashMap<String,ArrayList<Pair<String,Double>>>();
        val result: MutableList<Double> = mutableListOf<Double>();
        var numerator:String = "";
        var denominator:String = "";
        var value:Double = 1.0;

        for(i in equations.indices){
            numerator = equations[i][0];
            denominator = equations[i][1];
            value = values[i];

            if(!graph.contains(numerator)){
                graph.put(numerator,arrayListOf<Pair<String,Double>>());
            }
            graph[numerator]!!.add(Pair(denominator,value));

            if(!graph.contains(denominator)){
                graph.put(denominator,arrayListOf<Pair<String,Double>>());
            }
            graph[denominator]!!.add(Pair(numerator,1/value));
        }

        for(querie in queries){
            numerator = querie[0];
            denominator = querie[1];

            if(!graph.contains(numerator) || !graph.contains(denominator)){
                result.add(-1.0);
            }
            else if(numerator == denominator){
                result.add(1.0);
            }else{
                val bfs = ArrayDeque<Pair<String,Double>> ();
                val visited = HashSet<String>();
                var found:Boolean = false;

                bfs.add(Pair(numerator,1.0));

                while(!bfs.isEmpty() && !found){
                    var vertex:Pair<String,Double> = bfs.pollFirst();

                    if(!visited.contains(vertex.first)){
                        visited.add(vertex.first);

                        for(connections in graph[vertex.first].orEmpty()){
                            if(connections.first == denominator){
                                result.add(connections.second*vertex.second);
                                found = true;
                                break;
                            }else{
                                bfs.add(Pair(connections.first,vertex.second*connections.second));
                            }
                        }
                    }
                }

                if(!found){
                    result.add(-1.0);
                }
            }
        }

        return result.toDoubleArray();
    }
}