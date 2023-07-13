class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1]>b[1];
        });
        int ans = 0;
        for(auto box: boxTypes) {
            int t = (box[0] <= truckSize) ? box[0] : truckSize;
            ans += (t * box[1]);
            truckSize -= t;
            if(!truckSize) return ans;
        }
        return ans;
    }
};