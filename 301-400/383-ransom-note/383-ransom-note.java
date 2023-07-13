public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if(ransomNote==null || magazine==null) return false;
        if(ransomNote.length()==0 && magazine.length()==0) return true;
        
        char[] note = ransomNote.toCharArray();
        char[] maga = magazine.toCharArray();
        
        int l1 = note.length;
        int l2 = maga.length;
        
        int[] h1 = new int[26];
        int[] h2 = new int[26];
        
        for(char c : note){
            h1[c-'a']++;
        }
        
        for(char c : maga){
            h2[c-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(h1[i]>h2[i]) return false;
        }
        
        return true;
    }
}