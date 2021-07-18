class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%3) return {-1, -1};
        
        if(sum == 0) return {0, (int)arr.size()-1};
        
        int tOne = sum/3;
        
        int s = 0;
        while(arr[s] == 0) s++;
        
        int t = 0, m = -1;
        while(t != tOne+1) {
            t += arr[++m];
        }
        
        int e = m;
        while(t != 2*tOne+1) {
            t += arr[++e];
        }
        
        while(e < arr.size() && arr[s] == arr[m] && arr[m] == arr[e]) {
            s++, m++, e++;
        }
        if(e == arr.size()) return {s-1, m};
        return {-1, -1};
    }
};