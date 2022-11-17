class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // 1. compute the area of the two rectangles
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        // 2. compute the area of the overlapping rectangle
        int overlap = 0;

        // 2.1 compute the overlapping width
        int width = 0;
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        if (left < right) {
            width = right - left;
        }

        // 2.2 compute the overlapping height
        int height = 0;
        int bottom = max(ay1, by1);
        int top = min(ay2, by2);
        if (bottom < top) {
            height = top - bottom;
        }

        // 2.3 compute the overlapping area
        overlap = width * height;

        // 3. compute the total area
        int total = area1 + area2 - overlap;

        return total;
    }
};