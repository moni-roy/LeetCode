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
    int maxval = 0;
    public int longestConsecutive(TreeNode root) {
        longestPath(root);
        // dfs(root, null, 0, 0);
        return maxval;
    }
    public int[] longestPath(TreeNode root) {
        if (root == null)
            return new int[] {0,0};
        int inr = 1, dcr = 1;
        if (root.left != null) {
            int[] l = longestPath(root.left);
            if (root.val == root.left.val + 1)
                dcr = l[1] + 1;
            else if (root.val == root.left.val - 1)
                inr = l[0] + 1;
        }
        if (root.right != null) {
            int[] r = longestPath(root.right);
            if (root.val == root.right.val + 1)
                dcr = Math.max(dcr, r[1] + 1);
            else if (root.val == root.right.val - 1)
                inr = Math.max(inr, r[0] + 1);
        }
        maxval = Math.max(maxval, dcr + inr - 1);
        return new int[] {inr, dcr};
    }
    
     private void dfs(TreeNode p, TreeNode parent, int incr, int decr) {
        if (p == null) return;
        dfs(p.left, p, incr, decr);
        incr = (parent != null && p.val == parent.val + 1) ? incr + 1 : 1;
        decr = (parent != null && p.val == parent.val - 1) ? decr + 1 : 1;
        maxval = Math.max(maxval, decr);
        maxval = Math.max(maxval, incr);
        dfs(p.right, p, incr, decr);
    }
}