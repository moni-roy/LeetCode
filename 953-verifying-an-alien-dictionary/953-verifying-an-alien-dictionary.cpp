class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> order_map(26, 0);
        for (int i = 0; i < order.size(); ++i) {
            order_map[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); ++i) {
            if (!compare(words[i - 1], words[i], order_map)) {
                return false;
            }
        }
        return true;
    }
private:
    bool compare(string& a, string& b, vector<int>& order_map) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (order_map[a[i] - 'a'] < order_map[b[j] - 'a']) {
                return true;
            } else if (order_map[a[i] - 'a'] > order_map[b[j] - 'a']) {
                return false;
            } else {
                ++i;
                ++j;
            }
        }
        return i == a.size();
    }
};