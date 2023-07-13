class Solution {
public:
    int threeSumMulti(vector<int> &arr, int target) {
	map<int,long> mp;
	for (auto a: arr) mp[a]++;
	long ans = 0;
	for (auto it: mp) {
		for (auto it2: mp) {
			int i = it.first, j = it2.first;
			int k = target - i - j;
			if(mp.find(k) == mp.end()) continue;

			if(i == j && j == k) {
				ans += mp[i]*(mp[i]-1)*(mp[i]-2)/6;
			}
			else if(i == j && j != k) {
				ans += mp[i] * (mp[i]-1)/2 * mp[k];
			}
			else if(i< j && j<k) {
				ans += mp[i]*mp[j]*mp[k];
			}
			ans %= long(1e9 +7);
		}
	}
	return ans;
}
};