class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto a: arr) freq[a]++;
        int freq25 = arr.size() / 4;
        for(auto it: freq) {
            if(it.second > freq25) return it.first;
        }
        return 1;
    }
};