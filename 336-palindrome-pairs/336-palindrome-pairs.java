public class Solution {
    class TrieNode {
        TrieNode[] next;
        int index;
        List<Integer> list;
    
        TrieNode() {
            next = new TrieNode[26];
            index = -1;
            list = new ArrayList<>();
        }
    }
    
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> res = new ArrayList<>();
    
        TrieNode root = new TrieNode();
        
        /* build Trie */
        for (int i = 0; i < words.length; i++) {
            addWord(root, words[i], i);
        }
        
        /* search palindrome in Trie */
        for (int i = 0; i < words.length; i++) {
            search(words, i, root, res);
        }
        
        return res;
    }
    
    private void addWord(TrieNode root, String word, int index) {
        /* build trie with reverse of words */
        for (int i = word.length() - 1; i >= 0; i--) {
            if (root.next[word.charAt(i) - 'a'] == null) {
                root.next[word.charAt(i) - 'a'] = new TrieNode();
            }
    
            /* check if word[0..i] is palindrome, if so add the index of word to 
             * the index list of current root. the reason for doing this is when we have words like
             * ssl, l then trie will have l->s->s. when we search with l then at l node of trie it will
             * find that remaing part of string s->s is a palindrome, hence got the result. 
             */
            if (isPalindrome(word, 0, i)) {
                root.list.add(index);
            }
            root = root.next[word.charAt(i) - 'a'];
        }
        
        root.list.add(index);
        root.index = index; // indicates that word ends
    }
    
    private void search(String[] words, int i, TrieNode root, List<List<Integer>> list) {
        for (int j = 0; j < words[i].length(); j++) {  
            /* check if a word ends and remaining of current word is palindrome */
            if (root.index >= 0 && root.index != i && isPalindrome(words[i], j, words[i].length() - 1)) {
                list.add(Arrays.asList(i, root.index));
            }
    
            root = root.next[words[i].charAt(j) - 'a'];
            if (root == null) return;
        }
    
        for (int j : root.list) {
            if (i == j) continue;
            list.add(Arrays.asList(i, j));
        }
    }
    
    private boolean isPalindrome(String word, int i, int j) {
        while (i < j) {
            if (word.charAt(i++) != word.charAt(j--)) return false;
        }
    
        return true;
    }
}