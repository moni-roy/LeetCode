class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0, cur = 0;
        
        while(cur<height.size()) {
            while(!st.empty() && height[cur]>height[st.top()]) {
                int tp = st.top();
                st.pop();
                if(st.empty()) break;
                int d = cur - st.top() - 1;
                int h = min(height[cur], height[st.top()]) - height[tp];
                ans += d*h;
            }
            st.push(cur++);
        }
        return ans;
    }
};