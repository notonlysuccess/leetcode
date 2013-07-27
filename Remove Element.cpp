class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int m = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (A[i] != elem) {
                A[m++] = A[i];
            }
        }
        return m;
    }
};