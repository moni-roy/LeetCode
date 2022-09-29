class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int X) {
        vector<int> ans;
        int n = arr.size();
        int l = lower_bound(arr.begin(), arr.end(), X) - arr.begin();
        if (l == n) l--;
        if (arr[l] != X && l != 0) {
            if(abs(X - arr[l - 1]) == abs(X - arr[l])) {
                if(arr[l-1] < arr[l]) l--;
            }
            else {
                if(abs(X-arr[l-1]) < abs(X-arr[l])) l--;
            }
        }
        ans.push_back(arr[l]);
        int x = l - 1, y = l + 1;
        while (--k) {
            if (x < 0) ans.push_back(arr[y++]);
            else if (y >= n) ans.push_back(arr[x--]);
            else {
                if (abs(X - arr[x]) == abs(X - arr[y])) {
                    if (arr[x] < arr[y]) ans.push_back(arr[x--]);
                    else ans.push_back(arr[y++]);
                }
                else {
                    if (abs(X - arr[x]) < abs(X - arr[y])) ans.push_back(arr[x--]);
                    else ans.push_back(arr[y++]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};