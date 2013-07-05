class Solution {
public:
	int maxSubArray(int A[], int n) {
		int sum = 0;
		int ret = 0x80000000;
		for (int i = 0 ; i < n ; i ++) {
			ret = max(ret , A[i]);
			sum += A[i];
			ret = max(ret , sum);
			if (sum < 0) sum = 0;
		}
		return ret;
	}
};