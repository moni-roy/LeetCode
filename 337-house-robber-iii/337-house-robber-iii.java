/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    /* solution 3 */
    public int rob(TreeNode root) {
        int res[] = robDFS(root);
        return Math.max(res[0], res[1]);
    }
    int[] robDFS(TreeNode node){
        int [] res = new int[2];
        if(node==null) return res;
        int [] l = robDFS(node.left);
        int [] r = robDFS(node.right);
        res[0] = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        res[1] = l[0] + r[0] + node.val;
        return res;
    }
    
    /* solution 1 */
    public int rob1(TreeNode root) {
        return robDFS1(root)[1];
    }
    int[] robDFS1(TreeNode node){
        int [] res = new int[2];
        if(node==null) return res;
        int [] l = robDFS1(node.left);
        int [] r = robDFS1(node.right);
        res[0] = l[1] + r[1];
        res[1] = Math.max(res[0], l[0] + r[0] + node.val);
        return res;
    }
    
    /* solution 2 */
    HashMap<TreeNode, Integer> map = new HashMap<>();
    public int rob2(TreeNode root) {
        if(root==null) return 0;
        if(root.left==null && root.right==null){
            map.put(root, root.val);
            return root.val;
        }
        if(map.containsKey(root)) return map.get(root) ;
        
        int incl=0, excl=0;
        excl = rob(root.left) + rob(root.right);
        if(root.left!=null) incl += rob2(root.left.left) + rob2(root.left.right);
        if(root.right!=null) incl += rob2(root.right.left) + rob2(root.right.right);
        incl += root.val;
        
        map.put(root, Math.max(incl, excl));
        return Math.max(incl, excl);
    }
}