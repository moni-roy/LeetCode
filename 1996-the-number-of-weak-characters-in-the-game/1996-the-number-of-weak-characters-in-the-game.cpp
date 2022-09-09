class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = 0;
        int max_def = 0;
        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i][1] < max_def) {
                ++ans;
            }
            max_def = max(max_def, properties[i][1]);
        }
        return ans;
    }
};