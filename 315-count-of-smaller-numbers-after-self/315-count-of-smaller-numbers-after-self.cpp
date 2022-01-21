#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      return countSmallerUsingBIT(nums);
    }
private:
    void updateBIT(vector<int> &bit, int p, int &mx) {
        while(p < mx) {
            bit[p] += 1;
            p += p & (-p);
        }
    }

    int queryBIT(vector<int> &bit, int p) {
        int res = 0;
        while(p>0) {
            res += bit[p];
            p -= p & (-p);
        }
        return res;
    }

    vector<int> countSmallerUsingBIT(vector<int> &nums) {
        int offset = 1e4 + 1;
        int mx = 4 * 2e4;
        vector<int> bit(mx, 0);
        int n = nums.size();
        vector<int> ans(n, 0);
        updateBIT(bit, nums[n-1] + offset, mx);
        for(int i = n-2; i >= 0; i--) {
            ans[i] = queryBIT(bit, nums[i] + offset - 1);
            updateBIT(bit, nums[i] + offset, mx);
        }
        return ans;
    }

    // TLE
    vector<int> countSmallerUsingSet(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        multiset<int> mSet;
        mSet.insert(nums[n-1]);
        for(int i = n-2; i >= 0; i--) {
            auto nm = nums[i];
            mSet.insert(nm);
            auto it = mSet.lower_bound(nm);
            ans[i] = distance(mSet.begin(), it );
        }
        return ans;
    }
};
