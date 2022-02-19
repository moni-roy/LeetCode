class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 != 0) return {};
        vector<long long> res;
        long long sum = 0;
        while (sum < finalSum) {
            sum += 2;
            res.push_back(sum);
            finalSum -= sum;
        }
        if (finalSum != 0) res[res.size() - 1] += finalSum;
        return res;
    }
};