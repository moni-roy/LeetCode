class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd, ans;
        int i = 1;
        for(auto n: nums) {
            if(i) even.push_back(n);
            else odd.push_back(n);
            i = 1 - i;
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        i = 0;
        int ev = 0, od = 0;
        while (i < nums.size()) {
            if(i % 2) ans.push_back(odd[od++]);
            else ans.push_back(even[ev++]);
            i++;
        }
        
        return ans;
    }
};