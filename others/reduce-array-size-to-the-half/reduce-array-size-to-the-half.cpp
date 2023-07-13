class Solution {
public:
  int minSetSize(vector<int>& arr) {
    vector<int> fre(100005, 0);
    for (auto a : arr) {
      fre[a]++;
    }
    sort(fre.begin(), fre.end(), [](int a, int b) {
      return a > b;
      });
    int ans = 0, total = 0;
    for (auto f : fre) {
      if (total * 2 < arr.size()) {
        ans++;
        total += f;
      }
      else return ans;
    }
    return ans;
  }
};