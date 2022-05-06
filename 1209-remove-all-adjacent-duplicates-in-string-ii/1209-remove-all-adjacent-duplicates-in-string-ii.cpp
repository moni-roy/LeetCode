class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res = "";
        stack <pair<char, int>> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            } else {
                st.top().second++;
            }
            if (st.top().second == k) {
                st.pop();
            }
        }
        while (!st.empty()) {
            res.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};