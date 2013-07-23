class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret = 0;
        int lo = 0 , hi = height.size() - 1;
        while (lo < hi) {
            if (height[lo] < height[hi]) {
                ret = max(ret , (hi - lo) * height[lo]);
                lo ++;
            } else {
                ret = max(ret , (hi - lo) * height[hi]);
                hi --;
            }
        }
        return ret;
    }
};