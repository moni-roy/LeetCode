class Solution {
public:
    int largestInteger(int num) {
        vector<int> eventh, oddth, oddIndex, eventhIndex;
		// num to string
		string s = to_string(num);
		for(int i = 0; i < s.size(); i++) {
			int cur = s[i] - '0';
			if(cur % 2 == 0) {
				eventh.push_back(cur);
				eventhIndex.push_back(i);
			} else {
				oddth.push_back(cur);
				oddIndex.push_back(i);
			}
		}
		// sort reverse
		sort(eventh.begin(), eventh.end(), greater<int>());
		sort(oddth.begin(), oddth.end(), greater<int>());
		// merge
		vector<int> res(s.size());
		for(int i = 0; i < eventh.size(); i++) {
			res[eventhIndex[i]] = eventh[i];
		}
		for(int i = 0; i < oddth.size(); i++) {
			res[oddIndex[i]] = oddth[i];
		}
		int ans = 0;
		for(int i = 0; i < res.size(); i++) {
			ans = ans * 10 + res[i];
		}
		return ans;
    }
};