class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    queue<vector<string>> paths;
    paths.push({beginWord});

    unordered_set<string> vis;
    int lev = 1, ansL = INT_MAX;
    while (!paths.empty())
    {
      auto path = paths.front();
      paths.pop();
      if (path.size() > lev)
      {
        for (auto w : vis)
          st.erase(w);
        if (path.size() > ansL)
          break;
        else
          lev = path.size();
      }
      auto ls = path.back();
      for (int i = 0; i < ls.size(); i++)
      {
        auto s = ls;
        for (char c = 'a'; c <= 'z'; c++)
        {
          s[i] = c;
          if (st.find(s) != st.end())
          {
            auto nPath = path;
            nPath.push_back(s);
            vis.insert(s);
            if (s == endWord)
            {
              ans.push_back(nPath);
              ansL = lev;
            }
            else
            {
              paths.push(nPath);
            }
          }
        }
      }
    }
    return ans;
  }
};