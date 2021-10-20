class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = (r - l) * min(height[r], height[l]);
        while(l<r) {
            ans = max(ans, (r - l) * min(height[r], height[l]));
            if(height[r] > height[l]) l++;
            else r--;
        }
        return ans;
    }
};