class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int &value: target) {
            freq[value] ++;
        }
        for (int &value: arr) {
            freq[value]--;
        }
        for (int &value: target) {
            if (freq[value] != 0) return false;
        }
        return true;
    }
};