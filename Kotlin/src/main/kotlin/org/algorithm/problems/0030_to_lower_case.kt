// Problem Statement

// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
package org.algorithm.problems

class `0030_to_lower_case` {
    fun toLowerCase(str: String): String {
        var result: String = ""
        for (i in 0 until str.length) {
            var letter = str[i]
            if (letter >= 'A' && letter <= 'Z') {
                letter = 'a' + (letter - 'A')
            }
            result += letter
        }

        return result
    }
}