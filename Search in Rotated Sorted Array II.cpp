class Solution {
public:
    bool search(int A[], int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (A[mid] == target) {
                return true;
            }
            if (A[mid] == A[lo]) {
                while (A[mid] == A[lo]) {
                    lo ++;
                }
            } else if (A[mid] > A[lo]) {
                if (A[lo] <= target && target < A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (A[mid] < target && target <= A[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};