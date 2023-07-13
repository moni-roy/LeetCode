class Solution {
public:
    vector<int> grayCode(int n) {
        int l = 1<<n;
        vector<int> ans;
        for(int i = 0; i<l; i++) {
            int t = i ^ (i>>1);
            ans.push_back(t);
        }
        return ans;
    }
};