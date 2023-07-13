class Solution {
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        hs.push_back(0); hs.push_back(h);
        vs.push_back(0); vs.push_back(w);
        sort(hs.begin(), hs.end());
        sort(vs.begin(), vs.end());
        long long hm = 0, vm = 0;
        for(int i = 1; i < hs.size(); i++) {
            hm = hm > (hs[i] - hs[i-1]) ? hm : (hs[i] - hs[i-1]);
        }
        for(int i = 1; i < vs.size(); i++) {
            vm = vm > (vs[i] - vs[i-1]) ? vm : (vs[i] - vs[i-1]);
        }
        return (vm * hm) % 1000000007;
    }
};