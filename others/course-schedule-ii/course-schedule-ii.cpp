class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> out(numCourses, 0);
        vector<int> edge[numCourses];
        for(auto pre: prerequisites) {
            out[pre[0]]++;
            edge[pre[1]].push_back(pre[0]);
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(out[i] == 0) q.push(i); 
        }
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(auto v: edge[u]) {
                if(out[v]) {
                    out[v]--;
                    if(out[v] == 0) q.push(v);
                }
            }
        }
        return (ans.size() == numCourses)?ans:vector<int>{};
    }
};