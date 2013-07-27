class Solution {
public:
    int search(int A[], int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (A[mid] == target) {
                return mid;
            }
            if (A[0] <= A[mid]) {
                if (A[0] <= target && target < A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (A[mid] < target && target <= A[n-1]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};