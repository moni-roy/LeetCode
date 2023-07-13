public class Solution {
    public int[] searchRange(int[] A, int target) {
		int[] r = {-1,-1};
		if(A.length==0) return r;
		else{
			r[0] = getLowIndexItr(A, target, 0, A.length-1);
			if(r[0]==-1) {
				r[1] = -1;
				return r;
			}
			r[1] = getHighIndexItr(A, target, 0, A.length-1);
			return r;
		}
	}
	
    /* iterative low and high indices */
    private int getLowIndexItr(int[] A, int target,int l,int h) {
		if(h<l) return -1;
		if(l==h && A[l]==target) return l;
		
        int idx = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(A[mid] == target){
                idx = mid;
                h = mid-1;
            }
            else if(A[mid] < target) l = mid+1;
            else h = mid-1;
        }
        return idx;
	}
    
    private int getHighIndexItr(int[] A, int target,int l,int h) {
		if(h<l) return -1;
		if(l==h && A[l]==target) return l;
		
        int idx = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(A[mid] == target){
                idx = mid;
                l = mid+1;
            }
            else if(A[mid] < target) l = mid+1;
            else h = mid-1;
        }
        return idx;
	}
    
    /* recursive low and high indices*/
	private int getLowIndex(int[] A, int target,int l,int h) {
		if(h<l) return -1;
		if(l==h && A[l]==target) return l;
		int mid = l+(h-l)/2;
		if(A[mid]==target) {
			if(mid-l==1){
				if(A[l]==target) return l;
				else return mid;
			}
			else return getLowIndex(A, target, l, mid);
		}
		else if(A[mid]<target){
			return getLowIndex(A, target, mid+1, h);
		}
		else return getLowIndex(A, target, l, mid-1);
	}
	
	private int getHighIndex(int[] A, int target,int l,int h) {
		if(h<l) return -1;
		if(l==h && A[l]==target) return l;
		int mid = l+(h-l)/2;
		if(A[mid]==target) {
			if(h-mid==1){
				if(A[h]==target) return h;
				else return mid;
			}
			else return getHighIndex(A, target, mid, h);
		}
		else if(A[mid]<target){
			return getHighIndex(A, target, mid+1, h);
		}
		else return getHighIndex(A, target, l, mid-1);
	}
}