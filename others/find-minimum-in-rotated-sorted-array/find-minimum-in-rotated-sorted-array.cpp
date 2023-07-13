class Solution {
public:
    int findMin(vector<int>& a) {
        
        int l = 0, r = a.size()-1;
        if(r == 0 || a[r]>=a[l]) return a[l];
        while(l<=r){
            int m = (l + r)/2;
            if(a[0] <= a[m]) l = m+1;
            else r = m-1;
            // cout<<l<<" "<<r<<endl;
        }
        return a[l];
    }
};