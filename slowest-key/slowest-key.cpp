class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int p = 0, mx = 0;
        char c;
        for(int i = 0; i<releaseTimes.size(); i++) {
            int t = releaseTimes[i] - p;
            if(mx<t) {
                mx = t;
                c = keysPressed[i];
            }
            else if(mx == t){
                if(c < keysPressed[i]) c = keysPressed[i];
            }
            p = releaseTimes[i];
        }
        return c;
    }
};