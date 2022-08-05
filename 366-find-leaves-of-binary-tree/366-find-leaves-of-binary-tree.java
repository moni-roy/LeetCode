/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    HashMap<Integer, List<Integer>> map = new HashMap<>();
    
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> list = new LinkedList<>();
        if(root==null) return list;
        
        findLeavesHelp(root);
        int size = map.size();
        for(int i=0;i<size;i++){
            list.add(new LinkedList<Integer>());
        }
        
        for(int key: map.keySet()){
            List l = map.get(key);
            list.get(key).addAll(l);
        }
        
        return list;
    }
    
    private int findLeavesHelp(TreeNode root) {
        if(root==null) return -1;
                
        int l = findLeavesHelp(root.left);
        int r = findLeavesHelp(root.right);
        
        int level = Math.max(l, r) + 1;
        if(!map.containsKey(level)) map.put(level, new LinkedList<Integer>());
        map.get(level).add(root.val);
        
        return level;
    }
}