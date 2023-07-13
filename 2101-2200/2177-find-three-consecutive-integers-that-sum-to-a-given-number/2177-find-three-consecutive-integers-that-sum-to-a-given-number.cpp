class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long first = 0, second = 0, third = 0;
        
        first = (num - 3 ) / 3;
        second = first + 1;
        third = second + 1;
        
        if(first + second + third != num) {
            return vector<long long>();
        }
        return {first, second, third};
    }
};