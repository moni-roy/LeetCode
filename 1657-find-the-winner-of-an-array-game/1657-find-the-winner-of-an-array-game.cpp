class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current = 0, mx = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (mx > arr[i]) current ++;
            else current = 1;
            mx = max(mx, arr[i]);
            if (current >= k) return  mx;
        }
        return mx;
    }
};