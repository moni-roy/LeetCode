class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (long long)m*k) return -1;
        long long l = 1, r = accumulate(bloomDay.begin(), bloomDay.end(), 0LL);
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (can(bloomDay, m, k, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool can(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0, cur = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if(bloomDay[i]>mid){
              cur = 0;
                continue;
            } 
            cur++;
            if(cur==k) {
                cur = 0;
                cnt++;
            }
        }
        return cnt >= m;
    }
};