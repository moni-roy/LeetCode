class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int>rowSum(col);
    int ret = INT_MIN;
    for (int i = 0; i < row; i++)
    {
      fill(rowSum.begin(), rowSum.end(), 0);
      for (int r = i; r < row; r++)
      {
        for (int c = 0; c < col; c++)
        {
          rowSum[c] += matrix[r][c];
        }
        getResult(rowSum, k, ret);
        if (ret == k)
          return ret;
      }
    }
    return ret;
  }
private:
  void getResult(vector<int>& rowSum, int k, int &ret) {
    int sum = 0;
    set<int>st;
    st.insert(0);
    for (auto rs : rowSum) {
      sum += rs;
      auto it = st.lower_bound(sum - k);
      if (it != st.end()) {
        ret = max(ret, sum - *it);
      }
      st.insert(sum);
    }
  }
};