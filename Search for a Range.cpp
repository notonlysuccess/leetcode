class Solution {
private:
    int lower_bound(int a[],int lo,int hi,int target) {
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi + 1;
    }
    int upper_bound(int a[],int lo,int hi,int target) {
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = lower_bound(A , 0 , n - 1 , target);
        int upper = upper_bound(A , 0 , n - 1 , target);
        if (lower > upper - 1) {
            return vector<int>({-1,-1});
        }
        return vector<int>({lower, upper - 1});
    }
};