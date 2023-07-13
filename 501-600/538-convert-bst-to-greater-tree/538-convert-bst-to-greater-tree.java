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
    
    /* Solution 2 */
    int sum = 0;    
    public TreeNode convertBST(TreeNode root) {
        convert(root);
        return root;
    }
    
    private void convert(TreeNode cur) {
        if (cur == null) return;
        convert(cur.right);
        cur.val += sum;
        sum = cur.val;
        convert(cur.left);
    }
    
    /* Solution 1 */
    public TreeNode convertBST1(TreeNode root) {
        if(root==null) return root;
        
        convertBST1(root, 0);
        return root;
    }
    
    private int convertBST1(TreeNode root, int greaterSum) {
        if(root==null) return greaterSum;
        if(root.left==null && root.right==null) {
            root.val = root.val + greaterSum;
            return root.val;
        }
        
        int rightSum = convertBST1(root.right, greaterSum); // <-- update right sub-tree
        int leftSum = convertBST1(root.left, root.val+rightSum); // <-- update left sub-tree
        
        root.val = root.val + rightSum; // <-- update root val
        
        return leftSum;
    }
}