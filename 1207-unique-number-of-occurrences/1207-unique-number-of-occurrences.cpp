class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto a: arr) freq[a] ++;
        
        unordered_map<int, bool> seenFreq;
        for(auto it: freq) {
            if(seenFreq[it.second]) return false;
            seenFreq[it.second] = true;
        }
        return true;
    }
};