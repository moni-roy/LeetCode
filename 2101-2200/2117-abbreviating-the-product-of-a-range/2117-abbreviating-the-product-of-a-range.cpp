class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long suffix = 1, total = 0, zeros = 0, max_suffix = 1e11;
        double prefix = 1;
        for(long long i = left; i <= right; i++) {
            suffix *= i;
            prefix *= i;
            while(prefix >= 100000) {
                prefix /= 10;
                total = total == 0 ? 6 : total + 1;
            }
            while (suffix % 10 == 0) {
                suffix /= 10;
                zeros++;
            }
            suffix %= max_suffix;
        }
        string suffixString = to_string(suffix);
        string prefixString = to_string((int)prefix);
        
        string dots = (total - zeros) <= 10 ? "" : "...";
        string suffixRes = (total - zeros) < 5 ? "" : suffixString.substr(suffixString.size() - min(5LL, total - zeros - 5));
        
        string expo = "e" + to_string(zeros);
        return prefixString + dots + suffixRes + expo;
    }
};