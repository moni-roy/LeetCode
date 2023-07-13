class Solution {
public:
    int bitwiseComplement(int n) {
        int n1 = 1;
        while(n>n1) n1 = n1 * 2 + 1;
        return n ^ n1;
    }
};