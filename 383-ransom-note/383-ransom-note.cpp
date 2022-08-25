class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> rMap, mMap;
        for (auto c : ransomNote) rMap[c]++;
        for (auto c : magazine) mMap[c]++;
        
        for (auto c : ransomNote) {
            if (rMap[c] > mMap[c]) return false;
        }
        return true;
    }
};