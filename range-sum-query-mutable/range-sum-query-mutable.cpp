class NumArray {
public:
    vector<int> tree, num;
    
    NumArray(vector<int>& nums) {
        tree = vector<int>(150000, 0);
        num = nums;
        for(int i = 0; i< nums.size(); i++) {
            build(i, nums[i]);
        }
        
    }
    
    void build(int index, int val) {
        index++;
        while(index < 150000) {
            tree[index] += val;
            index += (index & (-index));
        }
    }
    
    void update(int index, int val) {
        int t = val;
        val = val - num[index];
        num[index] = t;
        index++;
        while(index < 150000) {
            tree[index] += val;
            index += (index & (-index));
        }
    }
    
    int sumRange(int left, int right) {
        right++;
        int ret = 0;
        while(right) {
            ret += tree[right];
            right -= (right & (-right));
        }
        
        while(left) {
            ret -= tree[left];
            left -= (left & (-left));
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */