class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;
        int ret = A[0] , sum = A[0];
        for (int i = 1 ; i < n ; i ++) {
            sum = sum < 0 ? A[i] : sum + A[i];
            ret = max(ret , sum);
        }
        return ret;
    }
};