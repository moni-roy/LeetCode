public class Solution {
    public boolean isAnagram(String s, String t) {
    	char[] sa = s.toCharArray();
    	char[] ta = t.toCharArray();
    	Arrays.sort(sa);
    	Arrays.sort(ta);
        return new String(sa).equals(new String(ta));
    }
}