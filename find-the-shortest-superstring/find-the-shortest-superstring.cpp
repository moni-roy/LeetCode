class Solution {
public:

  string shortestSuperstring(vector<string>& words) {
    int n = words.size();
    vector<vector<int> > gr(n, vector<int>(n, 0)), dp((1<<n)+ 1, vector<int>(n, -1)), parent((1<<n)+ 1, vector<int>(n, -1));

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n;j++) {
            if(i!=j) {
                for(int k = 1; k<min(words[i].size(), words[j].size()); k++) {
                    int l1 = words[i].size();
                    int l2 = words[j].size();
                    string s1 = words[i].substr(l1-k);
                    string s2 = words[j].substr(0, k);
                    if(s1 == s2){
                        gr[i][j]=k;
                    }
                }
            }
        }
    }
      
    int mx = INT_MAX;
    int p = 0;
    for (size_t i = 0; i < n; i++) {
      int t = words[i].size() + bitMask(1<<i, gr, words, dp, i, n, parent);
      if(t<mx){
        mx = t;
        p = i;
      }
    }

    string ans = words[p];
    int mask = 1<<p;
    for(int i = 1; i<n; i++) {
      int pr = p;
      p = parent[mask][p];
      ans += words[p].substr(gr[pr][p]);
      mask |= (1<<p);
    }
    return ans;
  }

  int bitMask(int mask, vector<vector<int>> &gr, vector<string> &words, vector<vector<int>> &dp, int p, int &n, vector<vector<int>> &parent) {
     if(mask == (1<<n)-1) return 0;
     if(dp[mask][p] != -1) return dp[mask][p];
     dp[mask][p] = INT_MAX;
     for(int i = 0; i<n; i++) {
       if(!(mask&(1<<i))) {
         int t = words[i].size() - gr[p][i] + bitMask(mask|(1<<i), gr, words, dp, i, n, parent);
         if(t < dp[mask][p]) {
           dp[mask][p] = t;
           parent[mask][p] = i;
         }
       }
     }
     return dp[mask][p];
  }
};
