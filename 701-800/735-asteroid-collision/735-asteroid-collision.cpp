class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto a : asteroids) {
            while (!res.empty() && res.back() > 0 && res.back() < -a) {
                res.pop_back();
            }
            if (res.empty() || res.back() < 0 || a > 0) {
                res.push_back(a);
            }
            else if (res.back() == -a) {
                res.pop_back();
            }
        }
        return res;
    }
};