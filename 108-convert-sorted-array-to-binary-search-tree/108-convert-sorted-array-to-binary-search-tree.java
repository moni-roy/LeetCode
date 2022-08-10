/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedArrayToBST(int[] num) {
        if(num.length<=0) return null;
        else if(num.length==1) return new TreeNode(num[0]);
        else{
        	return sortedArrayToBST(num, 0, num.length-1);
        }
    }
    
    public TreeNode sortedArrayToBST(int[] num, int low, int high) {
        if(high < low) return null;
        
        int mid = low + (high-low)/2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = sortedArrayToBST(num, low, mid-1);
        root.right = sortedArrayToBST(num, mid+1, high);
        
        return root;
    }
	
	private TreeNode sortedArrayToBST1(int[] num, int s, int e) {
        if(e<s) return null;
        
        int mid = s + (e-s)/2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = sortedArrayToBST(num, s, mid-1);
        root.right = sortedArrayToBST(num, mid+1, e);
        
        return root;
    }
}