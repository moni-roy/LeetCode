class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        return withoutExtraSpace(arr);
    }
private:
    int usingExtraSpace(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto a: arr) freq[a]++;
        int freq25 = arr.size() / 4;
        for(auto it: freq) {
            if(it.second > freq25) return it.first;
        }
        return 1;
    }
    
    int withoutExtraSpace(vector<int>& arr) {
        int n = arr.size();
        int cnt = n / 4;
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[i + cnt]) {
                return arr[i];
            }
        }
        return 1;
    }
};