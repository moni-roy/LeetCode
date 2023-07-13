class Solution {
public:
    int totalHammingDistance(vector<int>& A) {
        int ans = 0, n = A.size();
    for(int i = 0; i<32; i++) {
        int one = 0;
        for(auto a: A) {
            one += (a >> i) & 1;
        }
        ans += (one * (n-one));
    }
    return ans;
}
    
};