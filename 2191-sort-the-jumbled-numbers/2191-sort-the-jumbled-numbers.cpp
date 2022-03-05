class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        // create new mapping
        vector<pair<int, int>> mapping_vec;
        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            for (int j = 0; j < s.size(); j++) {
                s[j] = mapping[s[j] - '0'] + '0';
            }
            int new_num = stoi(s);
            mapping_vec.push_back({new_num, i});
        }
        // sort mapping_vec
        sort(mapping_vec.begin(), mapping_vec.end());
        // create new nums
        vector<int> new_nums;
        for (int i = 0; i < n; i++) {
            new_nums.push_back(nums[mapping_vec[i].second]);
        }
        return new_nums;
    }
};