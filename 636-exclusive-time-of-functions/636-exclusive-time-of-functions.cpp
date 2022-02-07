class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> stk;
        int prev = 0;
        for (auto& log : logs) {
            int id = stoi(log.substr(0, log.find(':')));
            int time = stoi(log.substr(log.find_last_of(':') + 1));
            if (log.find("start") != string::npos) {
                if (!stk.empty()) {
                    res[stk.top()] += time - prev;
                }
                stk.push(id);
                prev = time;
            } else {
                res[stk.top()] += time - prev + 1;
                stk.pop();
                prev = time + 1;
            }
        }
        return res;
    }
};