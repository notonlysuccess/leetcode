class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (A[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (lo == n || target != A[lo]) {
            return vector<int>(2,-1);
        }
        ret.push_back(lo);
        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (A[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ret.push_back(hi);
        return ret;
    }
};