class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        //  make unique
        set<int> st(nums.begin(), nums.end());
        vector<int> arr;
        for (auto x: st) arr.push_back(x);

        int j = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (j < arr.size() && arr[j] < arr[i] + n)
            {
                j ++;
            }
            int cnt = j - i;
            ans = min(ans, n - cnt);           
        }
        return ans;
    }
};