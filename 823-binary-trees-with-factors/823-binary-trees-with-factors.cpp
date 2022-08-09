class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        map<int,long> mp;
        long ans = 0;
        for(int i = 0; i < n; i++) {
            long way = 1;
            for (int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0){
                    long t = arr[i] / arr[j];
                    if(mp.find(t) != mp.end()) {
                        way += (mp[t] * mp[arr[j]]) % mod;
                        way %= mod;
                    }
                }
            }
            mp[arr[i]] = way;
            ans += way;
            ans %= mod;
        }
        return ans % mod;
    }       
};