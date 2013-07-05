class Solution {
public:
    int jump(int A[], int n) {
		int cur = 0;
		int step = 0;
		int last = 0;
		for (int i = 0 ; i < n ; i ++) {
			if (i > cur) {
				cur = last;
				step ++;
			}
			last = max(i + A[i] , last);
		}
		return step;
	}
};