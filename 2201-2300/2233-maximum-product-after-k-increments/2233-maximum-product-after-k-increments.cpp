class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
		}
		while (k--) {
			int x = pq.top();
			pq.pop();
			pq.push(x + 1);
		}
		long long res = 1;
		while (!pq.empty()) {
			res *= pq.top();
			res %= 1000000007;
			pq.pop();
		}
		return res;
    }
};