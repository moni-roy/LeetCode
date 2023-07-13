```
dfs(i):
if(i == size) return true;
if(dp[i] != empty) return dp[i]
​
if(i, i+1, i+2)
i == i+1
dfs(i+2)
i == i + 2
dfs(i+3)
i, i+1, i +2
dfs(i+3)
dp[i] = flag;
```