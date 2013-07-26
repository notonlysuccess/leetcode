class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k = n + m - 1;
        int i = m - 1 , j = n - 1;
        while (k >= 0) {
            if (j < 0) break;
            else if (i < 0) A[k--] = B[j--];
            else if (A[i] < B[j]) A[k--] = B[j--];
            else A[k--] = A[i--];
        }
    }
};