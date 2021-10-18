# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def dfs(root, l = -math.inf, r = math.inf):
            if root:
                if root.val<=l or r <= root.val:
                    return False
                return dfs(root.left, l, root.val) and dfs(root.right, root.val, r)
            return True
        return dfs(root)
        