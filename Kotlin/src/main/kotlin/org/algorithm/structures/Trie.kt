class Trie{
  class TrieNode (var childs: Array<TrieNode?> = arrayOfNulls<TrieNode?> (26), var endWord: Boolean = false)

  var root: TrieNode?;
  init{
    root = TrieNode();
  }

  fun addWord(word:String){
    var index = 0;
    var iterator : TrieNode? = root;
    while(index<word.length){
      var pos = word[index]-'a';
      if(iterator!!.childs[pos]==null){
        iterator.childs[pos] = TrieNode();
      }
      iterator = iterator.childs[pos];
      index++;
    }

    iterator?.endWord=true;
  }

  fun queryWord(word:String):Boolean{
    var iterator : TrieNode? = root;
    for(letter in word){
      var pos = letter-'a';
      if(iterator!!.childs[pos]==null)
        return false;
      iterator = iterator.childs[pos];
    }
    return iterator!!.endWord;
  }
}

fun main(args:Array<String>){
  var word:String = "teste";
  var trie:Trie = Trie();
  trie.addWord("testa");
  println(trie.queryWord(word));
}
