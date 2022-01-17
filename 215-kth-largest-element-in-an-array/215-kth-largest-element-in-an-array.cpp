class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestUsingSort(nums, k);
    }
private:
    int findKthLargestUsingSort(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    int findKthLargestUsingQuickSelect(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int pivot = partition(nums, left, right);
            if (pivot == k - 1) {
                return nums[pivot];
            } else if (pivot < k - 1) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return nums[left];
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    int findKthLargestUsingHeap(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};