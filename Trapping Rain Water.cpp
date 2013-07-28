class Solution {
public:
    int trap(int A[], int n) {
        int lo = 0;
        int hi = n - 1;
        int sum = 0;
        while (lo < hi) {
            if (A[lo] < A[hi]) {
                int k = lo + 1;
                for ( ; A[k] <= A[lo] ; k ++) {
                    sum += A[lo] - A[k];
                }
                lo = k;
            } else {
                int k = hi - 1;
                for ( ; A[k] < A[hi] ; k --) {
                    sum += A[hi] - A[k];
                }
                hi = k;
            }
        }
        return sum;
    }
};