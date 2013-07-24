class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = 0;
        if (dividend > 0) {
            flag ^= 1;
            dividend = -dividend;
        }
        if (divisor > 0) {
            flag ^= 1;
            divisor = -divisor;
        }
        int mul = 0;
        for ( ; dividend <= (long long)divisor <<(1+mul) ; mul ++);
        int ret = 0;
        for ( ; mul >= 0 ; mul--) {
            if (dividend <= divisor << mul) {
                dividend -= divisor << mul;
                ret |= (1<<mul);
            }
        }
        return flag ? -ret : ret;
    }
};