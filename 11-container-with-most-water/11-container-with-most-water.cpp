class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1, max_area = 0;
        while (lo < hi) {
            max_area = max(max_area, min(height[lo], height[hi]) * (hi - lo));
            if (height[lo] < height[hi])
                lo++;
            else
                hi--;
        }
        return max_area;
    }
};