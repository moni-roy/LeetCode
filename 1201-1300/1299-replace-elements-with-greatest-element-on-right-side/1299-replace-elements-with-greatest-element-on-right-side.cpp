class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx = -1;
        for(int i = arr.size() - 1; i >= 0; i--) {
            int t = arr[i];
            arr[i] = mx;
            mx = max(t, mx);
        }
        return arr;
    }
};