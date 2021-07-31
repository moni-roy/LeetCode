struct trie
{
	int cnt;
	trie *nd[30];
	trie()
	{
		cnt = 0;
		for (int i = 0; i < 30; i++)
			nd[i] = NULL;
	}
};

class MapSum
{
public:
	/** Initialize your data structure here. */
	trie *root;
    unordered_map<string, int> mp;
	MapSum()
	{
		root = new trie();
	}

	void insert(string s, int v)
	{
        int d = v - mp[s];
		trie *rt = root;
		for (int i = 0; i < (int)s.size(); i += 1)
		{
			int p = s[i] - 'a';
			if (rt->nd[p] == NULL)
			{
				rt->nd[p] = new trie();
			}
			rt = rt->nd[p];
            rt->cnt += d;
		}
		mp[s] = v;
	}
	int sum(string s)
	{
		trie *rt = root;
		for (int i = 0; i < (int)s.size(); i += 1)
		{
			int p = s[i] - 'a';
			if (rt->nd[p] == NULL)
			{
				return 0;
			}
			rt = rt->nd[p];
		}
		return rt->cnt;
	}
    
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
