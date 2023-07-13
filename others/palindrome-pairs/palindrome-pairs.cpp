class Solution
{
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    unordered_map<string, int> mp;
    vector<vector<int>> ans;
    int n = words.size();
    for (int i = 0; i < n; i++) {
      string s = words[i];
      reverse(s.begin(), s.end());
      mp[s] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= words[i].size(); j++) {
        // check suffix
        string s = words[i].substr(0, j);
        if (mp.find(s) != mp.end() && isPalindrome(words[i], j, words[i].size() - 1) && mp[s] != i) {
          ans.push_back({i, mp[s]});
        }
        // check prefix
        s = words[i].substr(j);
        if (j > 0 && mp.find(s) != mp.end() && isPalindrome(words[i], 0, j - 1) && mp[s] != i) {
          ans.push_back({mp[s], i});
        }
      }
    }
    return ans;
  }

  bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
  }
};