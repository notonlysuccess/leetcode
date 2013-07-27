class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (i == 0 || A[i] != A[i-1]) {
                A[m++] = A[i];
            }
        }
        return m;
    }
}; 