class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        for(auto d : digits) {
            freq[d]++;
        }
        vector<int> res;
        for(int i = 100; i < 1000; i+=2) {
            int n = i;
            int flag = 0;
            vector<int> tmp = freq;
            while (n) {
                int d = n % 10;
                if (tmp[d] == 0) {
                    flag = 1;
                    break;
                }
                tmp[d]--;
                n /= 10;
            }
            if (!flag) {
                res.push_back(i);
            }
        }
        return res;
    }
};