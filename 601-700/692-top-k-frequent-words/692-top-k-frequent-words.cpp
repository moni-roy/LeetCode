class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        return topKFrequentUsingHeap(words, k);
    }
private:
    vector<string> topKFrequentUsingHeap(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto& word : words) {
            freq[word]++;
        }
        auto cmp = [&](pair<int, string>& a, pair<int, string>& b) {
            return (a.first == b.first) ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto& p : freq) {
            pq.push(make_pair(p.second, p.first));
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res;        
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};