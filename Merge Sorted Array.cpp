class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int nm = n + m - 1;
        while (n && m) {
            if (A[m-1] > B[n-1]) {
                A[nm--] = A[--m];
            } else {
                A[nm--] = B[--n];
            }
        }
        while (n) {
            A[nm--] = B[--n];
        }
    }
};