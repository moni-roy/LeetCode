class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int curMax = 0, last = 0, secondLast = 0, lastCount = 0;
        for (auto fruit: fruits) {
            if(fruit == last || fruit == secondLast) {
                curMax++;
            } else {
                curMax = lastCount + 1;
            }
            ans = max(ans, curMax);

            // update last
            if (last != fruit) {
                secondLast = last;
                last = fruit;
                lastCount = 1;
            } else {
                lastCount++;
            }
        }
        return ans;
    }
};