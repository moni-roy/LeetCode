class Solution {

    int max;
    int[] csum;
    Random random;
    public Solution(int[] w) {
        csum = new int[w.length];
        
        csum[0] = w[0];
        for(int i=1; i<w.length; i++){
            csum[i] += csum[i-1] + w[i];
        }
        max = csum[w.length-1];
        
        random = new Random();
    }
    
    public int pickIndex() {
        int num = 1 + random.nextInt(max);
        int idx = getIndex(num);
        //System.out.println("num: "+num+", idx: " + idx);
        return (idx<0)?-idx-1:idx;
    }
    
    public int getIndex(int num){
        int low = 0, high = csum.length-1, idx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(csum[mid] == num) return mid;
            else if(csum[mid] < num){
                idx = -(mid+1)-1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return idx;
    }
    
    public int pickIndex2() {
        int num = 1 + random.nextInt(max);
        int idx = getIndex2(num);
        //System.out.println("num: "+num+", idx: " + idx);
        return idx;
    }
    
    public int getIndex2(int num){
        int low = 0, high = csum.length-1, idx = -1;
        while(low <= high){
            int mid = (high + low)/2;
            if(csum[mid] >= num){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high + 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */