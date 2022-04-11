class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
		int n = arr.size();
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			if (s.find(arr[i] * 2) != s.end()) return true;
			if (arr[i] % 2 == 0 && s.find(arr[i] / 2) != s.end()) return true;
			s.insert(arr[i]);
		}
		return false;
    }
};