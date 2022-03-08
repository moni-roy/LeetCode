public class Solution {
    public int findMin(int[] num) {
        if(num.length==0) return 0;
        else if(num.length==2) return (num[0]<num[1])?num[0]:num[1];
        else{
        	return findMin(num, 0, num.length-1);
        }
    }
	
	private int findMin(int[] num, int s, int e){
		if((e-s+1)==1) return num[s];		
		if((e-s+1)==2) return (num[s]<num[e])?num[s]:num[e];
		
		int mid = s+(e-s)/2;
        if(num[mid] < num[e]) return findMin(num, s, mid);
        else if(num[mid] > num[e]) return findMin(num, mid, e);
		else {
		    return Math.min(findMin(num, s, mid), findMin(num, mid, e));
		}
	}
}