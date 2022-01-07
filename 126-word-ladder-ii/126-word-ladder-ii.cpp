class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string> > ans;
        unordered_set<string> vis;
        
        queue<vector<string> > q;
        q.push({beginWord});
        while(!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                auto cPath = q.front(); q.pop();
                string last = cPath.back();
                for(int i = 0; i < last.size(); i++) {
                    string tmp = last;
                    for(char c = 'a'; c <= 'z'; c++) {
                        tmp[i] = c;
                        if(st.find(tmp) != st.end()) {
                            auto nPath = cPath;
                            nPath.push_back(tmp);
                            vis.insert(tmp);
                            if(tmp == endWord) {
                                ans.push_back(nPath);
                            }
                            else q.push(nPath);
                        }
                    }
                }
            }
            for(auto it: vis) st.erase(it);
        }
        return ans;
    }
};