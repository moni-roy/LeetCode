class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        return usingBinarySearch(arr, k);
    }
private:
    int usingBinarySearch(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        // left is the index of is larger than k
        // arr[right] + k - (arr[right] - right - 1) is the answer
        return left + k;
    }
};