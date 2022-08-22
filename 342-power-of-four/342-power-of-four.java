public class Solution {
    public boolean isPowerOfFour(int num) {
        boolean isSquare = ((num & (num-1)) == 0);
        boolean isSquareOf4 = ((num & 0x55555555) == num);
        return num!=0 && isSquare && isSquareOf4;
    }
}