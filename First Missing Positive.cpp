class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i = 0 ; i < n ; i ++) {
			int index = i;
			int val = A[i];
			while (index + 1 != val && val >= 1 && val <= n) {
				index = val - 1;
				val = A[index];
				A[index] = index + 1;
			}
		}
		for (int i = 0 ; i < n ; i ++) {
			if (i + 1 != A[i]) {
				return i + 1;
			}
		}
		return n + 1;
	}
};