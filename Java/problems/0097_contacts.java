// Problem Statement
// We're going to make our own Contacts application! The application must perform two types of operations:

// add name, where  is a string denoting a contact name. 
//   This must store  as a new contact in the application.
// find partial, where  is a string denoting a partial name to search the 
//   application for. It must count the number of contacts starting with  and print the count on a new line.
// Given  sequential add and find operations, perform each operation in order.

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class Solution {
    static int[] contacts(String[][] queries) {
        List<Integer> results = new ArrayList<>();
        Trie trie = new Trie();
        for (int i = 0; i < queries.length; i++) {
            if (queries[i][0].equals("add")) {
                trie.add(queries[i][1]);
            } else if (queries[i][0].equals("find")) {
                results.add(trie.find(queries[i][1]));
            }
        }
        int[] array = results.stream().mapToInt(i -> i).toArray();
        return array;
    }

    static class TrieNode {
        Integer hits = 0;
        private HashMap<Character, TrieNode> children = new HashMap<>();

        public void putChildIfAbsent(char ch) {
            children.putIfAbsent(ch, new TrieNode());
        }

        public TrieNode getChild(char ch) {
            return children.get(ch);
        }
    }

    static class Trie {
        TrieNode root = new TrieNode();

        public void add(String word) {
            TrieNode current = root;
            for (char ch : word.toCharArray()) {
                current.putChildIfAbsent(ch);
                current = current.getChild(ch);
                current.hits++;
            }
        }

        public int find(String prefix) {
            TrieNode current = root;
            for (char ch : prefix.toCharArray()) {
                current = current.getChild(ch);
                if (current == null) {
                    return 0;
                }
            }
            return current.hits;
        }
    }
}


class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[][] queries = {{"add", "hack"}, {"add", "hackerrank"}, {"find", "hac"}, {"find", "hak"}};
        System.out.println(Arrays.toString(solution.contacts(queries)));
    }
}
