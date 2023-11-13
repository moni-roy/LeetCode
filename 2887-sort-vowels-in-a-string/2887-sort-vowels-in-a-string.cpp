class Solution {
private:
bool isVowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I';
}
public:
    string sortVowels(string s) {
        unordered_map<char, int> mp;

        for (auto c: s) {
            if (isVowel(c)) {
                mp[c]++;
            }
        }
        string vowels = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i]))  ans += s[i];
            else {
                while(mp[vowels[j]] == 0) j++;
                ans += vowels[j];
                mp[vowels[j]]--;
            }
        }
        return ans;
    }
};