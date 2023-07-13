class Solution {
public:
    int numberOfWays(string corridor) {
        int i = 0;
        while (i < corridor.size() && corridor[i] != 'S') {
            i++;
        }
        int j = corridor.size() - 1;
        while (j >= 0 && corridor[j] != 'S') {
            j--;
        }
        if(j<=i) return 0;
        vector<long long> store;
        store.push_back(1);
        long long cnt = 0;
        for (int k = i; k <= j;) {
            if(corridor[k] == 'S') {
                cnt++;
            }
            if(cnt == 2) {
                int l = k + 1;
                while (l < j && corridor[l] != 'S') {
                    l++;
                }
                store.push_back(l - k);
                cnt = 0;
                k = l-1;
            }
            k++;

        }
        if(cnt != 0) return 0;
        long long res = 1;
        for (int k = 0; k < store.size(); k++) {
            res = res * store[k] % 1000000007;
        }
        return res;
    }
};