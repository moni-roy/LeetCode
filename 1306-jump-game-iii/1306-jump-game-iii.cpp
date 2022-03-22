class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        vector<int> vs(arr.size(), 0);
        return dfs(start, arr, vs);
    }
    
    bool dfs(int s, vector<int> &a, vector<int>&vs) {
        vs[s] = 1;
        if(a[s] == 0) return true;
        int l = s - a[s];
        int r = s + a[s];
        bool ret = false;
        if(l>=0 && vs[l] == 0) {
            ret |= dfs(l, a, vs);
        }
        if(r < a.size() && vs[r] == 0) {
            ret |= dfs(r, a, vs);
        }
        return ret;
    }
};