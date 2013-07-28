class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = 0;
        int two = n - 1;
        for (int i = zero ; i <= two ;) {
            if (A[i] == 0) {
                swap(A[zero++] , A[i++]);
            } else if (A[i] == 2) {
                swap(A[two--] , A[i]);
            } else {
                i ++;
            }
        }
    }
};