class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> stk;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};