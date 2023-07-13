class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i < s.size() - k + 1; i++) {
            string sub = s.substr(i, k);
            int a = stoi(sub);
            
            if(a && num % a == 0) ans++;
        }
        return ans;
    }
};