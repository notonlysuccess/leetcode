class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int cur = 0;
        int last = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (i > cur) {
                cur = last;
                step ++;
            }
            last = max(last , i + A[i]);
        }
        return step;
    }
};