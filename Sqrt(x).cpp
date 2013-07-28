class Solution {
public:
    int sqrt(int x) {
        int lo = 1 , hi = 0xffff;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (mid <= x / mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};