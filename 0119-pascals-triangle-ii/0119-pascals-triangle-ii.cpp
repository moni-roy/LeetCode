class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascalRow(rowIndex + 1, 1);
        pascalRow[0] = 1;
        for (int j = 1; j <= rowIndex; ++j) {
            vector<int> pascalRowNext(j + 1, 1);
            for(int i = 0; i <= j; ++i) {
                if(i == 0 || i == j) {
                    pascalRowNext[i] = 1;
                } else {
                    pascalRowNext[i] = pascalRow[i - 1] + pascalRow[i];
                }

            }
            pascalRow = pascalRowNext;
        }
        return pascalRow;
    }
};