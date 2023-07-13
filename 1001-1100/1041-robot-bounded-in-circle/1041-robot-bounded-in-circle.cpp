class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dx = 0, dy = 1;
        for (char c : instructions) {
            if (c == 'L') {
                int t = dx;
                dx = -dy;
                dy = t;
            }
            else if (c == 'R') {
                int t = dx;
                dx = dy;
                dy = -t;
            }
            else {
                x += dx;
                y += dy;
            }
        }
        return (x == 0 && y == 0) ||  (dx != 0 || dy != 1);
    }
};