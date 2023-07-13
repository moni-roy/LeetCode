class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;
        while (left <= right && directions[left] == 'L') left++;
        while (left <= right && directions[right] == 'R') right--;
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if(directions[i] != 'S') ans++;
        }
        return ans;
    }
};