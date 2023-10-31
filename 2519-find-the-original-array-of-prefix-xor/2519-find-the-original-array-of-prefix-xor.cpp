class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> result;
        result.push_back(pref[0]);
        int pre = pref[0], ret = pref[0];
        for (int i = 1; i < pref.size(); i++) {
            ret = pre ^ pref[i];
            result.push_back(ret);
            pre ^= ret;
        }
        return result;
    }
};