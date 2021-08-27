class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        s = preorder.split(",")
        c = 1
        for x in s:
            c -= 1
            if c < 0:
                return False
            if x.isdigit():
                c += 2
        return c == 0