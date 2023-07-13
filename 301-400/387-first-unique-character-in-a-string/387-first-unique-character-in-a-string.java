public class Solution {
    public int firstUniqChar(String s) {
        if(s==null || s=="") return -1;
        
        int[] list = new int[128];
        char[] ch = s.toCharArray();
        int len = s.length();
        
        for(int i=0;i<len;i++){
            list[ch[i]-'a']++;
        }
        
        for(int i=0;i<len;i++){
            if(list[ch[i]-'a'] == 1) return i;
        }
        
        return -1;
    }
}