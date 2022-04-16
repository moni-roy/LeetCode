class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
		int n = scores.size();
		// build adjacency list with top 3 scores
		vector<vector<int>> adj(n);
		for (auto& e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		// sort and get top 3 scores for each node in adjacency list
		for (int i = 0; i < n; ++i) {
			sort(adj[i].begin(), adj[i].end(), [&scores](int a, int b) {
				return scores[a] > scores[b];
			});
			if(adj[i].size() > 3) adj[i].resize(3);
		}

		int ans = -1;
		for(auto &e : edges) {
			for (auto &a : adj[e[0]]) {
				for (auto &b : adj[e[1]]) {
					if(a != b && a != e[1] && b != e[0] && a != e[0] && b != e[1]) {
						// cout << a << " " << e[0] << " " <<  e[1] << " " << b << " " << scores[e[0]] + scores[e[1]] + scores[a] + scores[b]<<endl;
						ans = max(ans, scores[e[0]] + scores[e[1]] + scores[a] + scores[b]);
					}
				}
			}
		}
		return ans;
    }
};