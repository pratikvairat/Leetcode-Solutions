class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; i++) {
            double num = sqrt(c - (i * i));
            if (num == (int)num) {
                return true;
            }
        }
        return false;
    }
};