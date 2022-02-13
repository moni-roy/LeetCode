class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> odd, even;
        
        int n = nums.size(), oS = 0, eS = 0;
        
        for(int i = 0; i < n; i++) {
            if(i&1) {
                odd[nums[i]]++;
                oS ++;
            } else {
                eS++;
                even[nums[i]]++;
            }
        }
        
        priority_queue<pair<int, int>> odd_pq, even_pq;
        for(auto it = odd.begin(); it != odd.end(); it++) {
            odd_pq.push({it->second, it->first});
        }
        for(auto it = even.begin(); it != even.end(); it++) {
            even_pq.push({it->second, it->first});
        }
        int ans = 0;
        while(!odd_pq.empty() && !even_pq.empty()) {
            
            int odd_val = odd_pq.top().first;
            int odd_key = odd_pq.top().second;
            int even_val = even_pq.top().first;
            int even_key = even_pq.top().second;

            if(odd_key != even_key) {
                return nums.size() - odd_val - even_val;
            } else {
                if(odd_val == even_val) {
                    ans += odd_val;
                    if(eS < oS) odd_pq.pop();
                    else even_pq.pop();
                }
                else if (odd_val > even_val) {
                    ans += even_val;
                    even_pq.pop();
                }else {
                    ans += odd_val;
                    odd_pq.pop();
                }
            }
        }
        return ans;
    }
};