package org.algorithm.structures

class Trie {
    data class TrieNode(
        var childs: Array<TrieNode?> = arrayOfNulls<TrieNode?>(26),
        var endWord: Boolean = false
    )

    var root: TrieNode?

    init {
        root = TrieNode()
    }

    fun addWord(word: String) {
        var index = 0;
        var iterator: TrieNode? = root;
        while (index < word.length) {
            val pos = word[index] - 'a';
            if (iterator!!.childs[pos] == null) {
                iterator.childs[pos] = TrieNode();
            }
            iterator = iterator.childs[pos];
            index++;
        }

        iterator?.endWord = true;
    }

    fun queryWord(word: String): Boolean {
        var iterator: TrieNode? = root;
        for (letter in word) {
            val pos = letter - 'a';
            if (iterator!!.childs[pos] == null)
                return false;
            iterator = iterator.childs[pos];
        }
        return iterator!!.endWord;
    }
}