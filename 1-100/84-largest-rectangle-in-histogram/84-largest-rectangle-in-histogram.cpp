class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return usingStack(heights);
    }
private:
    int usingStack(vector<int>& heights) {
        int maxArea = 0;
        stack<int> s;
        for (int i = 0; i <= heights.size(); i++) {
            int h = (i == heights.size()) ? 0 : heights[i];
            if (s.empty() || h >= heights[s.top()]) {
                s.push(i);
            } else {
                int t = s.top();
                s.pop();
                maxArea = max(maxArea, heights[t] * (s.empty() ? i : i - s.top() - 1));
                i--;
            }
        }
        return maxArea;
    }
};
