class CombinationIterator
{
    string characters;
    vector<string> combination;
    int combinationLength;
    int n;
    int k;
    int index;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        this->characters = characters;
        this->combinationLength = combinationLength;
        this->k = combinationLength;
        this->index = 0;
        this->combination = calculateCombination(characters, combinationLength);
        sort(combination.begin(), combination.end());
        this->n = combination.size();
    }

    string next()
    {
        string result = combination[index++];
        return result;
    }

    bool hasNext()
    {
        return index < n;
    }

    vector<string> calculateCombination(string characters, int combinationLength)
    {
        vector<string> res;
        if (combinationLength == 0)
        {
            res.push_back("");
            return res;
        }
        for (int i = 0; i < characters.size(); i++)
        {
            vector<string> temp = calculateCombination(characters.substr(i + 1), combinationLength - 1);
            for (int j = 0; j < temp.size(); j++)
            {
                res.push_back(characters[i] + temp[j]);
            }
        }
        return res;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */