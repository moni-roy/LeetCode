class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for(auto a: arr1) {
            int flag = upper_bound(arr2.begin(), arr2.end(), a + d) == lower_bound(arr2.begin(), arr2.end(), a - d);
            res += flag;
        }
        return res;
    }
};