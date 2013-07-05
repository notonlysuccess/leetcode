/*
binary search twice
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) {
            return -1;
        }
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (A[mid] >= A[0]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int start = lo;
        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int index = (mid + start);
            if (index >= n) index -= n;
            if (A[index] == target) {
                return index;
            } else if (A[index] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};


/*
binary search once
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] < A[lo]) {
                if (target == A[mid]) {
                    return mid;
                } else if (A[mid] > target || target >= A[lo]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (A[mid] == target) {
                    return mid;
                } else if (A[lo] <= target && target < A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};