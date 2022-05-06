class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        for(auto s: words1) freq1[s]++;
        for(auto s: words2) freq2[s]++;
        int res = 0;
        for(auto s: words1) {
            if(freq1[s] == freq2[s] && freq1[s] == 1) res++;
        }
        return res;
    }
};