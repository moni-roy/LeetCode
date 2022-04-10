class Solution {
        public:
                int calPoints(vector<string>  &ops) {
                        vector<int> value;
                        for(auto op: ops) {
                                if(op == "D") {
                                        int val = value.back();
                                        value.push_back(val * 2);
                                }
                                else if(op == "C") {
                                        value.pop_back();
                                }
                                else if(op == "+") {
                                        int sz = value.size();
                                        value.push_back(value[sz-1] + value[sz-2]);
                                }
                                else{
                                        value.push_back(stoi(op));
                                }
                        }
                        int ans = 0;
                        for(auto val: value) {
                                ans += val;
                        }
                        return ans;
                }
};