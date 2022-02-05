class Solution
{
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        // make possible digits
        int mins = targetSeconds / 60;
        int sec = targetSeconds % 60;
        long long ans = INT_MAX;
        
        if(mins < 100) {
            ans = min(ans, getCost(startAt, moveCost, pushCost, mins, sec));
        }
        
        // second possible digits
        if (sec + 60 < 100 && mins >= 1)
        {
            mins = mins - 1;
            sec = sec + 60;
            ans = min(ans, getCost(startAt, moveCost, pushCost, mins, sec));
        }

        return ans;
    }

    long long getCost(int startAt, long long moveCost, long long pushCost, int mins, int sec)
    {
        vector<int> minDigits;
        vector<int> secDigits;

        while (mins > 0)
        {
            minDigits.push_back(mins % 10);
            mins /= 10;
        }
        reverse(minDigits.begin(), minDigits.end());

        while (sec > 0)
        {
            secDigits.push_back(sec % 10);
            sec /= 10;
        }
        if(minDigits.size() != 0) {
            while (secDigits.size() < 2)
            {
                secDigits.push_back(0);
            }
        }
        reverse(secDigits.begin(), secDigits.end());

        vector<int> digits;
        for (int i = 0; i < minDigits.size(); i++)
        {
            digits.push_back(minDigits[i]);
        }
        for (int i = 0; i < secDigits.size(); i++)
        {
            digits.push_back(secDigits[i]);
        }
        int i = 0, start = startAt;
        long long cost = 0;
        while (i < digits.size())
        {
            int cur = digits[i];
            if (cur == start)
                cost += pushCost;
            else
            {
                cost += moveCost + pushCost;
                start = cur;
            }
            i++;
        }
        return cost;
    }
};