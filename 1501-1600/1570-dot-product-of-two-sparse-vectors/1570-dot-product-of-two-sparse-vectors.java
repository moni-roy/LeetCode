class SparseVector {
    
    int len;
    ArrayList<int[]> list;
    SparseVector(int[] nums) {
        len = nums.length;
        list = new ArrayList<>();
        for(int i=0; i<len; i++){
            if(nums[i] != 0)
                list.add(new int[]{i, nums[i]});
        }
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        if(len != vec.len)
            return 0;
        
        int i = 0, j = 0, isz = list.size(), jsz = vec.list.size();
        int r = 0;
        while(i<isz && j<jsz){
            if(list.get(i)[0] < vec.list.get(j)[0]) i++;
            else if(list.get(i)[0] > vec.list.get(j)[0]) j++;
            else{
                r += list.get(i)[1] * vec.list.get(j)[1];
                i++;
                j++;
            }
        }
        
        return r;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);