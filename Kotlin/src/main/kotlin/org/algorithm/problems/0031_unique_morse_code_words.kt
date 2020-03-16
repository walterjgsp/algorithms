// Problem Statement

// International Morse Code defines a standard encoding where each letter is
// mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b"
// maps to "-...", "c" maps to "-.-.", and so on.
//
// For convenience, the full table for the 26 letters of the English alphabet is given below:
//
// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// Now, given a list of words, each word can be written as a concatenation
// of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-",
// (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation,
// the transformation of a word.
//
// Return the number of different transformations among all words we have.
package org.algorithm.problems

class `0031_unique_morse_code_words` {

    private val letters = mutableListOf<String>(".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..")

    fun toMorse(word: String): String {
        var result: String = ""
        for (c in word) {
            result += letters[c - 'a']
        }
        return result
    }

    fun uniqueMorseRepresentations(words: Array<String>): Int {

        val unique = mutableSetOf<String>()

        for (word in words) {
            unique.add(toMorse(word))
        }

        return unique.size
    }
}