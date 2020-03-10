/* Problem Statement

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
] */
package org.algorithm.problems

class `0047_group_of_anagrams` {

    fun getStringArray(word : String): String{
        var counter:IntArray = IntArray(26);

        for(letter in word){
            counter[letter-'a']++;
        }

        return counter.joinToString();
    }

    fun groupAnagrams(strs: Array<String>): List<List<String>> {

        var groups: HashMap<String,MutableList<String>> = HashMap<String,MutableList<String>> ();
        var result: MutableList<MutableList<String>> = mutableListOf<MutableList<String>> ();

        for(word in strs){
            var wordStringArray: String = getStringArray(word);
            if(groups.containsKey(wordStringArray)){
                groups.get(wordStringArray)!!.add(word);
            }else{
                groups.put(wordStringArray,mutableListOf<String>(word));
            }
        }

        for((key, value) in groups){
            result.add(value);
        }

        return result;
    }
}

