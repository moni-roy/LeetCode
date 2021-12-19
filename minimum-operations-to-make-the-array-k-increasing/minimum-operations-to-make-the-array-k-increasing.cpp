class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; i++) {
            vector <int> tmp;
            for (int j = i; j < n; j += k) {
                tmp.push_back(arr[j]);
            }
            ans += tmp.size() - LIS(tmp);
        }
        return ans;
    }

    int LIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis;
        for (int i = 0; i < n; i++) {
            if (lis.empty() || arr[i] >= lis.back()) {
                lis.push_back(arr[i]);
            } else {
                int j = lower_bound(lis.begin(), lis.end(), arr[i] + 1) - lis.begin();
                lis[j] = arr[i];
            }
        }
        return lis.size();
    }
        
};