class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin() , num.end());
        int ret , closest = INT_MAX;
        for (int i = 0 ; i < num.size() ; i ++) {
            int lo = i + 1;
            int hi = num.size() - 1;
            while (lo < hi) {
                int sum = num[i] + num[lo] + num[hi];
                if (sum < target) {
                    lo ++;
                } else {
                    hi --;
                }
                if (abs(sum - target) < closest) {
                    closest = abs(sum - target);
                    ret = sum;
                }
            }
        }
        return ret;
    }
};