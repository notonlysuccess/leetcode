class Solution {
private:
    int lower_bound(int A[],int lo,int hi,int target) {
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (A[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi + 1;
    }
public:
    int searchInsert(int A[], int n, int target) {
        return lower_bound(A , 0 , n - 1 , target);
    }
};