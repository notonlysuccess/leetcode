class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = 0;
		if (divisor > 0) {
			divisor = -divisor;
			flag ^= 1;
		}
		if (dividend > 0) {
			dividend = -dividend;
			flag ^= 1;
		}
		int mul = 0;
		for ( ; dividend <= ((long long)divisor << (1+mul)) ; mul ++);
		int ret = 0;
		for ( ; mul >= 0 ; mul --) {
			if (dividend <= (divisor << mul)) {
				ret |= (1<<mul);
				dividend -= (divisor << mul);
			}
		}
		if (flag) return -ret;
		return ret;
	}
};