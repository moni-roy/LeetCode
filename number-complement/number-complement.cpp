class Solution {
public:
    int findComplement(int num) {
        // find 1's complement of num
        
        // find the number of bits in num
        int bits = 0;
        int n = num;
        while (n) {
            n = n >> 1;
            bits++;
        }
        cout<<bits<<endl;

        long long mask = (long long) (1 << bits) - 1;
        return num ^ mask;
    }
};