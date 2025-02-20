class Solution {
private:
int stringToInteger(const string &num) {
    return stoi(num, 0, 2);
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> existings;
        for (auto &num: nums) {
            existings.insert(stringToInteger(num));
        }
        for (int num = 0; num <= nums.size(); ++num) {
            if (existings.find(num) == existings.end()) {
                string str = bitset<16>(num).to_string();
                return str.substr(16 - nums.size());
            }
        }
        return "";
    }
};