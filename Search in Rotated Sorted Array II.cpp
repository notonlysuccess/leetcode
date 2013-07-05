class Solution {
public:
    bool search(int A[], int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[lo] < A[mid]) {
                if (A[lo] <= target && target <= A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (A[lo] > A[mid]){
                if (A[lo] <= target || target <= A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                lo ++;
            }
        }
        return false;
    }
};