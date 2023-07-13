class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(maxVal);
        int m = primes.size();

        unordered_map<int, int> firstIdx, lastIdx;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 0; j < m && primes[j] * primes[j] <= num; j++) {
                if (num % primes[j] == 0) {
                    if (!firstIdx.count(primes[j])) firstIdx[primes[j]] = i;
                    lastIdx[primes[j]] = i;
                    while (num % primes[j] == 0) num /= primes[j];
                }
            }
            if (num > 1) {
                if (!firstIdx.count(num)) firstIdx[num] = i;
                lastIdx[num] = i;
            }
        }

        vector<int> sum(n + 1, 0);
        for (auto first : firstIdx) {
            sum[first.second]++;
            sum[lastIdx[first.first]]--;
        }

        for (int i = 0; i < n-1; i++) {
            if (i) sum[i] += sum[i - 1];
            if (sum[i] == 0) return i;
        }
        return -1;
    }

    vector<int> getPrimes(int n) {
        vector<int> primes;
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return primes;
    }
};