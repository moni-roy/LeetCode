class NumArray {
public:
    long BIT[40005]={0};
    
    void update(int x,int value) {
        while(x<40005) {
            BIT[x] += value;
            x += (x &(-x));
        }
    }
    int query(int x) {
        int ret = 0;
        while(x) {
            ret += BIT[x];
            x -= (x &(-x));
            
        }
        return ret;
    }
    
    NumArray(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            update(i+1, nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */