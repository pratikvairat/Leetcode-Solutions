class Solution {
public:
    int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    bool canMeasureWater(int x, int y, int target) {
        int n = abs(x - y);
        if (x + y < target) {
            return false;
        }
        if (x == target || y == target || x + y == target) {
            return true;
        }
        return target % gcd(x, y)==0;
    }
};