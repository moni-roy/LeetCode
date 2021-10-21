class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0 for i in range(n)] for j in range(n)]
        f = 1
        x,y = 0, 0
        for a in range(n*n):
            # print (x, y, a+1)
            ans[y][x] = a+1
            if f == 1:
                x+=1
                if x>=n or ans[y][x]!=0:
                    f=2
                    x-=1
                    y+=1
            elif f == 2:
                y+=1
                if y>=n or ans[y][x]!=0:
                    f=3
                    y-=1
                    x-=1
            elif f == 3:
                x-=1
                if x<0 or ans[y][x]!=0:
                    x+=1
                    f=0
                    y-=1
            else:
                y-=1
                if y<0 or ans[y][x]!=0:
                    y+=1
                    f = 1
                    x+=1
        return ans
        