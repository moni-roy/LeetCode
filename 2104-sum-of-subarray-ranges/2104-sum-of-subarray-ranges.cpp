class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n, 0), right(n, 0);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
       
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (left[i] * right[i]) * arr[i];
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n, 0), right(n, 0);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
       
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (left[i] * right[i]) * arr[i];
        }
        return ans;
    }
};