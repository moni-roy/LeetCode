class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num > 0)
        {
            return getNum(num);
        }
        else
        {
            num = -num;
            return -getNum2(num);
        }
    }
    long long getNum(long long num)
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        // first digit is not 0
        int i = 0;
        while (i < s.size() && s[i] == '0')
        {
            i++;
        }
        if (i != s.size())
        {
            string res = "";
            res += s[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (j == i)
                {
                    continue;
                }
                else
                    res += s[j];
            }
            return stoll(res);
        }
        return 0;
    }
    long long getNum2(long long num)
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        return stoll(s);
    }
};