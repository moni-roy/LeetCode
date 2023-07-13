class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        return usingSlidingWindow(low, high);
    }
private:
    vector<int> usingGreedy(int low, int high) {
        vector<int> res;
        int n = 1;
        while (n <= 9) {
            int num = n, d = n + 1;
            while (num <= high && d <= 10) {
                if (num >= low) res.push_back(num);
                num = num * 10 + (d++);
            }
            n++;
        }
        sort(res.begin(), res.end());
        return res;
    }
    vector<int> usingSlidingWindow(int low, int high) {
        string nums = "123456789";
        int n = nums.size();
        vector<int> res;
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();
        for (int i = lowLen; i <= highLen; i++) {
            for (int j = 0; j <= n - i; j++) {
                int num = stoi(nums.substr(j, i));
                if (num >= low && num <= high) res.push_back(num);
            }
        }
        return res;
    }
};