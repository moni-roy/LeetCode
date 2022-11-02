class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty()) return -1;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(end) == bankSet.end()) return -1;
        queue<string> q;
        q.push(start);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string cur = q.front();
                q.pop();
                if (cur == end) return step;
                for (int j = 0; j < cur.size(); ++j) {
                    char ch = cur[j];
                    for (char c = 'A'; c <= 'Z'; ++c) {
                        if (c == ch) continue;
                        cur[j] = c;
                        if (bankSet.find(cur) != bankSet.end()) {
                            q.push(cur);
                            bankSet.erase(cur);
                        }
                    }
                    cur[j] = ch;
                }
            }
            ++step;
        }
        return -1;
    }
}; // using vs code github copilot