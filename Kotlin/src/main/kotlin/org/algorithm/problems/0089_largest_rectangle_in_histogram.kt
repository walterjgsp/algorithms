// Problem Statement
// Given n non-negative integers representing the histogram's bar height where the
// width of each bar is 1, find the area of largest rectangle in the histogram.
package org.algorithm.problems

import java.util.Stack;

class `0089_largest_rectangle_in_histogram` {
    fun largestRectangleArea(heights: IntArray): Int {
        var result: Int = 0;
        val helper = Stack<Int>();

        for (i in heights.indices) {
            while (!helper.empty() && heights[helper.peek()] >= heights[i]) {
                val lastHeight = heights[helper.peek()];
                helper.pop();

                val area: Int = lastHeight * if (helper.empty()) {
                    i
                } else {
                    i - helper.peek() - 1
                }

                result = maxOf(result, area);

            }
            helper.add(i);
        }

        while (!helper.empty()) {
            val currHeight = heights[helper.peek()];
            helper.pop();

            val area: Int = currHeight * if (helper.empty()) {
                heights.size
            } else {
                heights.size - helper.peek() - 1
            }

            result = maxOf(result, area);
        }

        return result;
    }
}