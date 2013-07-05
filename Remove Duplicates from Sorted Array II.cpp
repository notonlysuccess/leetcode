class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m = 0;
        for (int i = 0; i < n ; i ++) {
            if (i < 2) {
                A[m++] = A[i];
            } else if (A[i] != A[m-1] || A[i] != A[m-2]) {
                A[m++] = A[i];
            }
        }
        return m;
    }
};