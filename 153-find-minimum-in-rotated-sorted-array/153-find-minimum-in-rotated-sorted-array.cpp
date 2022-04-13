class Solution {
public:
    int findMin(vector<int>& a) {
        int low = 0, high = a.size() - 1;
		if (high == 0 || a[low] < a[high]) return a[low];
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (a[0] <= a[mid]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return a[low];
	}
};