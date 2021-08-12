class Solution
{
public:
	bool canReorderDoubled(vector<int> &arr)
	{
		map<int, int> mp;
        for(auto a: arr) {
            mp[a]++;
        }
        sort(arr.begin(), arr.end(), [](int a, int b){ return abs(a)<abs(b);});
        
        for(auto a: arr) {
            if(mp[a] == -1) continue;
            if(mp[a] > mp[a*2]) return false;
            mp[a*2] -= mp[a];
            mp[a] = -1;
        }
		return true;
	}
};