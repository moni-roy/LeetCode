class BIT {
public:
    BIT(int n) {
        this->n = n;
        bit.resize(n + 1);
        for (int i = 0; i <= n; i++) bit[i] = 0;
    }
    void update(int i, long long v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
private:
    vector<long long> bit;
    int n;
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        vector<int> nums(n);
        for(int i = 0; i < n; i++) nums[nums1[i]] = i;
        
        BIT bit1(n), bit2(n);
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            int num = nums[nums2[i]];
            
            ans += bit2.query(num);
            long long less = bit1.query(num);
            
            bit1.update(num + 1, 1);
            bit2.update(num + 1, less);
        }
        return ans;
    }
};