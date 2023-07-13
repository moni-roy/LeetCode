"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        rootTop = root
        while rootTop:
            row = rowTop = Node()
            top = rootTop
            while top:
                for c in [top.left, top.right]:
                    row.next = c
                    if c:
                        row = row.next
                top = top.next
            rootTop = rowTop.next
        return root