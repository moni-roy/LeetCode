class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            int cnt = 0;
            while (j < n && tasks[j] == tasks[i]) {
                cnt += 1;
                j++;
            }
            if(cnt < 2) return -1;
            ans += (cnt + 2) / 3;
            i = j;
        }
        return ans;
    }
};