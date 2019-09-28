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

import java.util.*;

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String [] words = {"eat", "tea", "tan", "ate", "nat", "bat"};
        System.out.println(sol.groupAnagrams(words));
    }
}

class Solution {
    
    private String generateKey(String word){
        int [] counter = new int[26];
        String key = "";
        int index = 0;
        
        for(char c : word.toCharArray()){
            counter[c-'a']++;
        }
        
        while(index<counter.length){
            if(counter[index]==0){
                index++;
            }else{
                key+= (index+'a');
                counter[index]--;
            }
        }
        
        return key;
    }
    
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> groups = new HashMap<String,List<String>>();
        List<List<String>> result = new ArrayList<List<String>>();
        
        for(String word : strs){
            String key = generateKey(word);
            
            if(!groups.containsKey(key)){
                groups.put(key, new ArrayList<String>());
            }
                
            groups.get(key).add(word);
        }
        
        for(List<String> list : groups.values()){
            result.add(list);
        }
        
        return result;
    }
}