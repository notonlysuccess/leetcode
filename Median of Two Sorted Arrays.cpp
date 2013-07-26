class Solution {
private:
    double search(int A[],int B[],int lo,int hi,int m,int n) {
        if (lo > hi) {
            return search(B , A , 0 , n - 1 , n , m);
        }
        int mid = (lo + hi) >> 1;
        int median = (m + n) >> 1;
        int midb = median - mid - 1;
        if (mid > median) {
            return search(A , B , lo , mid - 1 , m , n);
        }
        if (midb >= n) {
            return search(A , B , mid + 1 , hi , m , n);
        }
        if (midb >= 0 && B[midb] > A[mid]) {
            return search(A , B , mid + 1 , hi , m , n);
        } else if (midb + 1 < n && B[midb+1] < A[mid]) {
            return search(A , B , lo , mid - 1 , m , n);
        } else {
            if ((n+m)&1) {
                return A[mid];
            } else if (midb == -1) {
                return (A[mid] + A[mid-1]) / 2.0;
            } else if (mid == 0) {
                return (A[mid] + B[midb]) / 2.0;
            } else {
                return (A[mid] + max(A[mid-1] , B[midb]) ) / 2.0;
            }
        }
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return search(A , B , 0 , m - 1 , m , n);
    }
};