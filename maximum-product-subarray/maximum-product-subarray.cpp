class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0], min_product = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = max_product;
            max_product = max(max(max_product * nums[i], min_product * nums[i]), nums[i]);
            min_product = min(min(tmp * nums[i], min_product * nums[i]), nums[i]);
            result = max(result, max_product);
        }
        return result;
    }
};