class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        for (int i = 0; i < list1.size(); ++i) map1[list1[i]] = i;
        int min_sum = INT_MAX, min_index = 0;
        vector<string> res;
        for (int i = 0; i < list2.size(); ++i) {
            if (map1.find(list2[i]) != map1.end()) {
                int sum = i + map1[list2[i]];
                if (sum < min_sum) {
                    min_sum = sum;
                    min_index = i;
                    res.clear();
                    res.push_back(list2[i]);
                } else if (sum == min_sum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};