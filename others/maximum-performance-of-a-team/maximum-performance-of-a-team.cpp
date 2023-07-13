class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int> pq;
        vector<pair<int,int>>v;
        
        for(int i = 0;i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first>b.first;
        });
        
        long long sum = 0, ans = 0;
        
        for(auto p: v) {
            int e = p.first;
            int s = p.second;
            // cout<<e<< " ";
            
            if(pq.size()>k-1) {
                sum += pq.top();
                pq.pop();
            }
            pq.push(-s);
            
            sum += s;
            long long t = (sum * e);
            ans = (ans < t)? t : ans;
        }
        return ans%mod;
    }
};