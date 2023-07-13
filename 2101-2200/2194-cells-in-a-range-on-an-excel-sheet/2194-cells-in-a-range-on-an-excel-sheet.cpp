class Solution {
public:
    vector<string> cellsInRange(string s) {
        char start_col = s[0], end_col = s[3];
        int start_row = s[1] - '0', end_row = s[4] - '0';
        vector<string> res;
        for (char col = start_col; col <= end_col; col++) {
            for (int row = start_row; row <= end_row; row++) {
                res.push_back(string(1, col) + to_string(row));
            }
        }
        return res;
    }
};