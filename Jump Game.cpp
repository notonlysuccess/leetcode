class Solution {
public:
    bool canJump(int A[], int n) {
        int index = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (i <= index) {
                index = max(index , i + A[i]);
            }
        }
        return index >= n - 1;
    }
};