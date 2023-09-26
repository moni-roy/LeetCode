class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        # print(last)
        stack = []
        for i, c in enumerate(s):
            if c in stack:
                continue
            while stack and stack[-1] > c and last[stack[-1]] > i:
                stack.pop()
            stack.append(c)
        return "".join(c for c in stack)