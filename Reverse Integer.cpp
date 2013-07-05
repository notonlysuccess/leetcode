class Solution {
public:
	int reverse(int x) {
		if (x < 0) return -reverse(-x);
		int ret = 0;
		while (x) {
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret;
	}
};