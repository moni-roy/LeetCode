class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        vector<int> freq(100005, 0);
        for (auto a : arr)
        {
            freq[a]++;
        }
        sort(freq.begin(), freq.end(), [](int a, int b)
             { return a > b; });

        int ans = 0, total = 0;
        for (auto f : freq)
        {
            if (total * 2 < arr.size())
            {
                ans++;
                total += f;
            }
            else
                return ans;
        }
        return ans;
    }
};