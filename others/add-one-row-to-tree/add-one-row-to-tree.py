# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        def dfs(node, h, dr):
            if h == d:
                t = TreeNode(v)
                if dr == 0:
                    t.left = node
                else:
                    t.right = node
                return t
            if not node:
                return node
            node.left = dfs(node.left, h+1, 0)
            node.right = dfs(node.right, h+1, 1)
            return node
        return dfs(root, 1, 0)
            