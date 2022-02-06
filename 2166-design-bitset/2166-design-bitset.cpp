class Bitset
{
public:
    // declare global bitset
    unordered_set<int> zero, oneSet;
    int flipFlag;
    int size;

    Bitset(int size)
    {
        flipFlag = 0;
        this->size = size;
        // initialize bitset
        for (int i = 0; i < size; i++)
        {
            zero.insert(i);
        }
    }

    void fix(int idx)
    {
        if (flipFlag)
        {
            if (zero.find(idx) == zero.end())
            {
                oneSet.erase(idx);
                zero.insert(idx);
            }
        }
        else
        {
            if (oneSet.find(idx) == oneSet.end())
            {
                zero.erase(idx);
                oneSet.insert(idx);
            }
        }
    }

    void unfix(int idx)
    {
        if (!flipFlag)
        {
            if (zero.find(idx) == zero.end())
            {
                oneSet.erase(idx);
                zero.insert(idx);
            }
        }
        else
        {
            if (oneSet.find(idx) == oneSet.end())
            {
                zero.erase(idx);
                oneSet.insert(idx);
            }
        }
    }

    void flip()
    {
        flipFlag = !flipFlag;
    }

    bool all()
    {
        if (flipFlag)
        {
            return oneSet.size() == 0;
        }
        else
        {
            return zero.size() == 0;
        }
    }

    bool one()
    {
        if (!flipFlag)
        {
            return oneSet.size() >= 1;
        }
        else
        {
            return zero.size() >= 1;
        }
    }

    int count()
    {
        if (!flipFlag)
        {
            return oneSet.size();
        }
        else
        {
            return zero.size();
        }
    }

    string toString()
    {
        string s = "";
        if (flipFlag)
        {
            for (int i = 0; i < size; i++)
            {
                if (zero.find(i) != zero.end())
                {
                    s += "1";
                }
                else
                {
                    s += "0";
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (oneSet.find(i) != oneSet.end())
                {
                    s += "1";
                }
                else
                {
                    s += "0";
                }
            }
        }
        return s;
    }
};