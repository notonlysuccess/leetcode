class Solution {
public:
    int sqrt(int x) {
        int lo = 0;
        int hi = min(x , 0xffff);
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int sq = (mid+1)*(mid+1);
            if (sq < 0 || sq > x) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hi + 1;
    }
};