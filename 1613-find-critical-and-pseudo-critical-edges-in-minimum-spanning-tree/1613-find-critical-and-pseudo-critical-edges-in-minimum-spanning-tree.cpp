class UnionFind {
    vector <int> parent, comSize;
    int maxComSize;
public:
    UnionFind(int n) {
        maxComSize = 1;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            comSize.push_back(1);
        }
    }
    int find(int a) {
        return (parent[a] == a)? a : (parent[a] = find(parent[a]));
    }
	bool connect(int x, int y){
		int xx = find(x), yy = find(y);
		if(xx == yy) return false;
        if (comSize[xx] < comSize[yy]) swap(xx, yy);
        parent[yy] = xx;
        comSize[xx] += comSize[yy];
        if (comSize[xx] > maxComSize) maxComSize = comSize[xx];
        return true;
	}
    int getMaxComSize() { return maxComSize; }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int idx = 0; idx < edges.size(); idx++) edges[idx].push_back(idx);
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        int mst_weight =  calculate_mst_weight(n, -1, edges, false).first;
        vector<vector<int>> ans(2);
        for (int idx = 0; idx < edges.size(); idx++) {
            auto mst_tmp = calculate_mst_weight(n, idx, edges, false);
            if (mst_tmp.first > mst_weight || mst_tmp.second < n) {
                ans[0].push_back(edges[idx][3]);
            }
            else if (calculate_mst_weight(n, idx, edges, true).first == mst_weight) {
                ans[1].push_back(edges[idx][3]);
            }
        }
        return ans;
    }
    pair<int, int> calculate_mst_weight(int n, int ingore_index, vector<vector<int>>& edges, bool pseudo_critical) {
        UnionFind uf(n);
        int mst_weight = 0;
        if (pseudo_critical) {
            mst_weight = edges[ingore_index][2];
            uf.connect(edges[ingore_index][0], edges[ingore_index][1]);
        }
        for (int index = 0; index < edges.size(); index++) {
            if (index == ingore_index) continue;
            if (uf.connect(edges[index][0], edges[index][1])) {
                mst_weight += edges[index][2];
            }
        }
        return {mst_weight, uf.getMaxComSize()};
    }
};