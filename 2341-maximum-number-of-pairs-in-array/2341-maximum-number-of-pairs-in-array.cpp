class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        vector <int> freq(101, 0);
        for(auto num: nums) freq[num] ++;
        int ansx = 0, ansy = 0;
        
        for(auto fr: freq) {
            ansx += fr/2;
            ansy += fr % 2;
        }
        
        return {ansx, ansy};
    }
};