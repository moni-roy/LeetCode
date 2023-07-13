class Solution {
    public List<String> generateParenthesis(int n) {
        if(n<1) return new LinkedList<>();
        return generateParenthesis("", n, n);
    }
    
    private List<String> generateParenthesis(String s, int l, int r) {
        List<String> list = new LinkedList<>();
        if(l==0 && r==0) {
            list.add(s);
            return list;
        }
        
        List<String> left = null;
        List<String> right = null;
        if(l>0) left = generateParenthesis(s+"(", l-1, r);
        if(l<r) right = generateParenthesis(s+")", l, r-1);
        
        if(left!=null) list.addAll(left);
        if(right!=null) list.addAll(right);
        return list;
    }
}