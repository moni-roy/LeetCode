#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fibo = vector<int>(31, 0);
    int fib(int n)
    {
        if (n < 2)
            return n;
        if (fibo[n] != 0)
            return fibo[n];
        fibo[n] = fib(n - 1) + fib(n - 2);
        return fibo[n];
    }
};