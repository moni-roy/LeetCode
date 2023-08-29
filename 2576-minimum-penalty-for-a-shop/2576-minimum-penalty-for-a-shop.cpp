class Solution {
public:
    int bestClosingTime(string customers) {
        int cur = count(customers.begin(), customers.end(), 'Y');
        int min = cur;
        int idx  = 0;
        for (int i = 0; i < customers.size(); i++) {
            auto c = customers[i];
            if (c == 'Y') {
                cur--;
            } else {
                cur++;
            }
            if (cur < min) {
                min = cur;
                idx = i + 1;
            }
        }
        return idx;
    }
};